#pragma once

#include <PowerDiagram/support/operators/norm_2.h>
#include <PowerDiagram/support/operators/norm_1.h>
#include <PowerDiagram/support/operators/sp.h>
#include "LegendreTransform.h"
#include "PolyCon.h"

#define DTP template<class Scalar,int nb_dims>
#define UTP PolyCon<Scalar,nb_dims>

DTP UTP::PolyCon( Span<Point> f_dirs, Span<Scalar> f_offs, Span<Point> b_dirs, Span<Scalar> b_offs ) : f_dirs( f_dirs ), f_offs( f_offs ), b_dirs( b_dirs ), b_offs( b_offs ) {
}

DTP void UTP::get_power_diagram( const std::function<void( PowerDiagram<Scalar,nb_dims> &pd )> &f ) {
    Vec<Scalar> weights( FromSize(), f_offs.size() );
    for( PI i = 0; i < weights.size(); ++i )
        weights[ i ] = norm_2_p2( f_dirs[ i ] ) - 2 * f_offs[ i ];

    Vec<PI> indices( FromSize(), f_offs.size() );
    for( PI i = 0; i < indices.size(); ++i )
        indices[ i ] = i;

    PointTreeCtorParms point_tree_ctor_params;
    PowerDiagram<Scalar,nb_dims> pd( point_tree_ctor_params, f_dirs, weights, indices, b_dirs, b_offs );

    f( pd );
}

DTP Opt<std::tuple<Scalar,typename UTP::Point>> UTP::value_and_gradient( Point x ) {
    Opt<std::tuple<Scalar,typename UTP::Point>> res;
    for_each_cell( [&]( Cell<Scalar,nb_dims> &cell ) {
        if ( cell.contains( x ) )
            res = std::tuple<Scalar,typename UTP::Point>{ cell.height( x ), *cell.orig_point };
    } );
    return res;
}

DTP PolyCon<Scalar,nb_dims> UTP::legendre_transform() {
    LegendreTransform lt( *this );
    return lt.transform();
}

DTP void UTP::for_each_cell( const std::function<void( Cell<Scalar,nb_dims> &cell )> &f ) {
    get_power_diagram( [&]( PowerDiagram<Scalar,nb_dims> &pd ) {
        pd.for_each_cell( f );
    } );
}

DTP void UTP::display_vtk( VtkOutput &vo, bool elevation ) {
    for_each_cell( [&]( const Cell<Scalar,nb_dims> &cell ) {
        const auto coord_change = [&]( Vec<Scalar,3> &point ) {
            if ( nb_dims <= 2 && elevation )
                point[ nb_dims ] = sp( point, *cell.orig_point ) - ( norm_2_p2( *cell.orig_point ) - *cell.orig_weight ) / 2;
        };
        cell.display_vtk( vo, coord_change );
    } );
}

DTP void UTP::normalize() {
    if constexpr ( nb_dims >= 1 ) {
        Vec<bool> rm_cells( FromSizeAndItemValue(), f_dirs.size(), false );
        for_each_cell( [&]( auto &cell ) {
            // fuzzy warning
            rm_cells[ cell.orig_index ] = cell.measure() == 0;
        } );

        f_dirs.remove_indices( rm_cells );
        f_offs.remove_indices( rm_cells );
    }

    auto apply_corr = []( auto &vec, const Vec<bool> &keep ) {
        int last_keep = vec.size();
        for( int i = 0; i < last_keep; ++i ) {
            if ( ! keep[ i ] ) {
                while( --last_keep > i && ! keep[ last_keep ] );
                vec[ i ] = std::move( vec[ last_keep ] );
            }
        }
        vec.resize( last_keep );
    };

    auto sort_vecs = []( auto &a, auto &b ) {
        Vec<Tup<Point,Scalar>> c( FromReservationSize(), a.size() );
        for( PI i = 0; i < a.size(); ++i )
            c.push_back( a[ i ], b[ i ] );

        std::sort( c.begin(), c.end(), Less() );

        for( PI i = 0; i < a.size(); ++i ) {
            a[ i ] = std::move( c[ i ].template get<0>() );
            b[ i ] = std::move( c[ i ].template get<1>() );
        }
    };

    // remove unused
    std::tuple<Vec<bool>,Vec<bool>> used = used_fbs();
    apply_corr( f_dirs, std::get<0>( used ) );
    apply_corr( f_offs, std::get<0>( used ) );
    apply_corr( b_dirs, std::get<1>( used ) );
    apply_corr( b_offs, std::get<1>( used ) );

    // normalize directions
    for( PI i = 0; i < b_dirs.size(); ++i ) {
        Scalar n = norm_1( b_dirs[ i ] );
        b_dirs[ i ] = b_dirs[ i ] / n;
        b_offs[ i ] = b_offs[ i ] / n;
    }

    // sort rows
    sort_vecs( f_dirs, f_offs );
    sort_vecs( b_dirs, b_offs );
}

DTP PI UTP::nb_bnds() const {
    return b_dirs.size();
}

DTP std::tuple<Vec<bool>,Vec<bool>> UTP::used_fbs() {
    Vec<bool> used_fs{ FromSizeAndItemValue(), f_dirs.size(), false };
    Vec<bool> used_bs{ FromSizeAndItemValue(), b_dirs.size(), false };
    for_each_cell( [&]( Cell<Scalar,nb_dims> &cell ) {
        cell.get_used_fbs( used_fs, used_bs, nb_bnds() );
    } );
    return { used_fs, used_bs };
}

DTP UTP operator+( const UTP &a, const UTP &b ) {
    using  Point = UTP::Point;

    Vec<Point>  f_dirs( FromReservationSize(), a.f_dirs.size() * b.f_dirs.size() );
    Vec<Scalar> f_offs( FromReservationSize(), a.f_offs.size() * b.f_offs.size() );
    for( PI i = 0; i < a.f_dirs.size(); ++i ) {
        for( PI j = 0; j < b.f_dirs.size(); ++j ) {
            f_dirs << a.f_dirs[ i ] + b.f_dirs[ j ];
            f_offs << a.f_offs[ i ] + b.f_offs[ j ];
        }
    }

    Vec<Point>  b_dirs{ FromConcatenation(), a.b_dirs, b.b_dirs };
    Vec<Scalar> b_offs{ FromConcatenation(), a.b_offs, b.b_offs };

    return { f_dirs, f_offs, b_dirs, b_offs };
}

#undef DTP
#undef UTP
