#pragma once

#include <PowerDiagram/support/operators/norm_2.h>
#include <PowerDiagram/support/operators/sp.h>
#include <PowerDiagram/support/P.h>
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
        const auto coord_change = [&]( VtkOutput::Pt &point ) {
            if ( nb_dims <= 2 && elevation )
                point[ nb_dims ] = sp( point, *cell.orig_point ) - ( norm_2_p2( *cell.orig_point ) - *cell.orig_weight ) / 2;
        };
        cell.display_vtk( vo, coord_change );
    } );
}

DTP void UTP::normalize() {
    for( PI i = 0; i < b_dirs.size(); ++i ) {
        Scalar n = norm_2( b_dirs[ i ] );
        b_dirs[ i ] = b_dirs[ i ] / n;
        b_offs[ i ] = b_offs[ i ] / n;
    }
}

DTP PI UTP::nb_bnds() const {
    return b_dirs.size();
}

#undef DTP
#undef UTP
