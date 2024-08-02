#include <PowerDiagram/support/Rational.h>
#include <polycon/PolyCon.h>
#include "catch_main.h"

constexpr int nb_dims = 3;
using Scalar = double; // Rational;
using Point = Vec<Scalar,nb_dims>;

auto vertices_of( auto &pd ) {
    Vec<Point> points;
    pd.for_each_cell( [&]( const Cell<Scalar,nb_dims> &cell ) {
        cell.for_each_vertex( [&]( const Vertex<Scalar,nb_dims> &v ) {
            // for( const Point &point : points )
            //     if ( all( point == v.pos ) )
            //         return;
            for( const Point &point : points )
                if ( norm_2_p2( point - v.pos ) == 0 )
                    return;
            points << v.pos;
        } );
    } );
    std::sort( points.begin(), points.end(), Less() );
    return points;
}

TEST_CASE( "PolyCon 3D", "" ) {
    Vec<Point> fun_dirs{
        { -5, -5, -5 },
        { -5, -5,  5 },
        { -5,  5, -5 },
        { -5,  5,  5 },
        {  5, -5, -5 },
        {  5, -5,  5 },
        {  5,  5, -5 },
        {  5,  5,  5 }
    };
    Vec<Scalar> fun_offs{
        -5, -5, -4, -4, 4, 4, 5, 5
    };

    Vec<Point> bnd_dirs{ };
    Vec<Scalar> bnd_offs{ };

    PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
    pa.normalize();
    P( pa );

    // for( auto o : vertices_of( pa ) )
    //     P( o );

    VtkOutput va;
    pa.display_vtk( va );
    va.save( "pa.vtk" );

    PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
    pb.normalize();
    P( pb );

    pb.for_each_cell( [&]( auto &cell ) {
        P( cell.measure() );
    } );


    // P( vertices_of( pb ) );

    VtkOutput vb;
    pb.display_vtk( vb );
    vb.save( "pb.vtk" );

    pb.for_each_cell( [&]( const Cell<Scalar,nb_dims> &cell ) {
        P( cell.measure() );
    } );
}

