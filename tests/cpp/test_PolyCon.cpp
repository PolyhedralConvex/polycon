#include <polycon/PolyCon.h>
#include "catch_main.h"

// TEST_CASE( "PolyCon 1D", "" ) {
//     constexpr int nb_dims = 1;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { -0.5 }, { +0.65 } };
//     Vec<Scalar> fun_offs{ 0, 0 };

//     Vec<Point> bnd_dirs{ { -1 } };
//     Vec<Scalar> bnd_offs{ 1 };

//     PolyCon<Scalar,nb_dims> pc( fun_dirs, fun_offs, bnd_dirs, bnd_offs );

//     VtkOutput vo;
//     pc.display_vtk( vo );
//     vo.save( "pc.vtk" );

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
// }

// TEST_CASE( "PolyCon 1D", "" ) {
//     constexpr int nb_dims = 1;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { -0.6 }, { +0.0 }, { +0.7 } };
//     Vec<Scalar> fun_offs{ 0.1, 0.2, 1.0 };

//     Vec<Point> bnd_dirs{ { +1. } };
//     Vec<Scalar> bnd_offs{ 3. };
//     // Vec<Point> bnd_dirs{};
//     // Vec<Scalar> bnd_offs{};

//     PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     pa.normalize();
//     P( pa );

//     VtkOutput vo;
//     pa.display_vtk( vo );
//     vo.save( "pc.vtk" );

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
//     P( pb );

//     PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
//     P( pc );
// }

// TEST_CASE( "PolyCon 2D", "" ) {
//     constexpr int nb_dims = 2;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { 1., 0.1 }, { 0.1, -0.7 }, { 0., +0.7 } };
//     Vec<Scalar> fun_offs{ 0, 0.1, 0.2 };

//     Vec<Point> bnd_dirs{ { +1., 0. }, { -1., 0. }/*, { 0., +1. }, { 0., -1. }*/ };
//     Vec<Scalar> bnd_offs{ 1., 1./*, 1., 1.*/ };
//     // Vec<Point> bnd_dirs{};
//     // Vec<Scalar> bnd_offs{};

//     PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     pa.normalize();
//     P( pa );

//     VtkOutput vo;
//     pa.display_vtk( vo );
//     vo.save( "pc.vtk" );

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
//     P( pb );

//     PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
//     P( pc );
// }

TEST_CASE( "PolyCon 3D", "" ) {
    constexpr int nb_dims = 3;
    using Scalar = double;

    using Point = Vec<Scalar,nb_dims>;

    Vec<Point> fun_dirs{ { 1., 0.1, 0.0 }, { 0.1, -0.7, 0.0 }, { 0., +0.7, 0.3 }, { 0., 0.0, +0.8 } };
    Vec<Scalar> fun_offs{ 0, 0.1, 0.2, 0.3 };

    Vec<Point> bnd_dirs{
        { +1., 0., 0. }, { -1., 0., 0. },
        { 0., +1., 0. }, { 0., -1., 0. },
        { 0., 0., +1. }, { 0., 0., -1. }
    };
    Vec<Scalar> bnd_offs{ 5., 5., 5., 5., 7., 7. };
    // Vec<Point> bnd_dirs{};
    // Vec<Scalar> bnd_offs{};

    PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
    pa.normalize();
    P( pa );

    VtkOutput va;
    pa.display_vtk( va );
    va.save( "pa.vtk" );

    PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
    P( pb );

    VtkOutput vb;
    pb.display_vtk( vb );
    vb.save( "pb.vtk" );

    PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
    P( pc );

    VtkOutput vc;
    pc.display_vtk( vc );
    vc.save( "pc.vtk" );
}
