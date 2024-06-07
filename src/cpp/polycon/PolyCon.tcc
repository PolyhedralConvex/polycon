#include <PowerDiagram/support/operators/norm_2.h>
#include <PowerDiagram/support/operators/sp.h>
#include <PowerDiagram/support/P.h>
// #include "LegendreTransform.h"
#include "PolyCon.h"

PolyCon::PolyCon( Span<Point> f_dirs, Span<Scalar> f_offs, Span<Point> b_dirs, Span<Scalar> b_offs ) : f_dirs( f_dirs ), f_offs( f_offs ), b_dirs( b_dirs ), b_offs( b_offs ) {
}

void PolyCon::get_power_diagram( const std::function<void( PowerDiagram &pd )> &f ) {
    Vec<Scalar> weights( FromSize(), f_offs.size() );
    for( PI i = 0; i < weights.size(); ++i )
        weights[ i ] = norm_2_p2( f_dirs[ i ] ) - 2 * f_offs[ i ];

    Vec<PI> indices( FromSize(), f_offs.size() );
    for( PI i = 0; i < indices.size(); ++i )
        indices[ i ] = i;

    PointTreeCtorParms point_tree_ctor_params;
    PowerDiagram pd( point_tree_ctor_params, f_dirs, weights, indices, b_dirs, b_offs );

    f( pd );
}

PolyCon PolyCon::legendre_transform() {
    // LegendreTransform lt( power_diagram );
    // return lt.transform();
    TODO;
}

void PolyCon::for_each_cell( const std::function<void( Cell &cell )> &f ) {
    get_power_diagram( [&]( PowerDiagram &pd ) {
        pd.for_each_cell( f );
    } );
}

void PolyCon::display_vtk( VtkOutput &vo, bool elevation ) {
    for_each_cell( [&]( const Cell &cell ) {
        const auto coord_change = [&]( VtkOutput::Pt &point ) {
            if ( PD_DIM <= 2 )
                point[ PD_DIM ] = sp( point, *cell.orig_point ) - ( norm_2_p2( *cell.orig_point ) - *cell.orig_weight ) / 2;
        };
        cell.display_vtk( vo, coord_change );
    } );
}
