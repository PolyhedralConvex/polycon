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

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
//     P( pb );

//     // VtkOutput vo;
//     // pb.display_vtk( vo );
//     // vo.save( "pc.vtk" );
//     //pb.for_each_cell( [&]( const auto &c ) {} )

//     PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
//     P( pc );
// }

// TEST_CASE( "PolyCon 3D", "" ) {
//     constexpr int nb_dims = 3;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { 1., 0.1, 0.0 }, { 0.1, -0.7, 0.0 }, { 0., +0.7, 0.3 }, { 0., 0.0, +0.8 } };
//     Vec<Scalar> fun_offs{ 0.0, 0.1, 0.2, 0.3 };

//     // Vec<Point> bnd_dirs{
//     //     { +1., 0., 0. }, { -1., 0., 0. },
//     //     { 0., +1., 0. }, { 0., -1., 0. },
//     //     { 0., 0., +1. }, { 0., 0., -1. }
//     // };
//     // Vec<Scalar> bnd_offs{ 5., 5., 5., 5., 5., 5. };
//     Vec<Point> bnd_dirs{ { 1, 0, 0 } };
//     Vec<Scalar> bnd_offs{ 5 };

//     PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     pa.normalize();
//     P( pa );

//     // VtkOutput va;
//     // pa.display_vtk( va );
//     // va.save( "pa.vtk" );

//     // pa.normalize();
//     // P( pa );

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
//     // pb.normalize();
//     P( pb );

//     // VtkOutput vb;
//     // pb.display_vtk( vb );
//     // vb.save( "pb.vtk" );

//     PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
//     pc.normalize();
//     P( pc );

//     // VtkOutput vc;
//     // pc.display_vtk( vc );
//     // vc.save( "pc.vtk" );
// }

// TEST_CASE( "PolyCon 1D", "" ) {
//     constexpr int nb_dims = 1;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { -0.5 }, { +0.65 } };
//     Vec<Scalar> fun_offs{ 0, 0 };

//     Vec<Point> bnd_dirs{};
//     Vec<Scalar> bnd_offs{};

//     PolyCon<Scalar,nb_dims> pc( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     P( pc );

//     VtkOutput vo;
//     pc.display_vtk( vo );
//     vo.save( "pc.vtk" );

//     // PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
// }

TEST_CASE( "PolyCon 3D spec", "" ) {
    constexpr int nb_dims = 3;
    using Scalar = double;
    using Point = Vec<Scalar,nb_dims>;

    Vec<Point> fun_dirs{ { 5.000000, 5.039216, 7.254902 }, { 5.000000, -5.750000, 5.906250 }, { -0.124563, 0.015134, 0.221187 } };
    Vec<Scalar> fun_offs{ 5.503922, 4.425000, -0.123050 };
    Vec<Point> bnd_dirs{ { 0.000000, -0.752577, 0.658505 }, { -0.995562, -0.054701, -0.076582 }, { 0.000000, 0.581238, 0.813733 }, { 0.000000, 0.447214, -0.894427 }, { -0.172931, 0.194547, -0.965529 }, { 0.000000, 0.000000, -1.000000 } };
    Vec<Scalar> bnd_offs{ 0.526804, -0.061265, 0.650987, 0.044721, -0.153476, 0.000000 };

    PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
    P( pa );

    VtkOutput va;
    pa.display_vtk( va );
    va.save( "pa.vtk" );
}
