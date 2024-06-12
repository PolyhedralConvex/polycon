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

TEST_CASE( "PolyCon 3D", "" ) {
    constexpr int nb_dims = 3;
    using Scalar = double;

    using Point = Vec<Scalar,nb_dims>;

    Vec<Point> fun_dirs{ { 1., 0.1, 0.0 }, { 0.1, -0.7, 0.0 }, { 0., +0.7, 0. }, { 0., 0.0, +0.7 } };
    Vec<Scalar> fun_offs{ 0.0, 0.1, 0.2, 0.3 };

    // Vec<Point> bnd_dirs{
    //     { +1., 0., 0. }, { -1., 0., 0. },
    //     { 0., +1., 0. }, { 0., -1., 0. },
    //     { 0., 0., +1. }, { 0., 0., -1. }
    // };
    // Vec<Scalar> bnd_offs{ 5., 5., 5., 5., 5., 5. };
    Vec<Point> bnd_dirs{ { 1, 0, 0 } };
    Vec<Scalar> bnd_offs{ 5 };

    PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
    pa.normalize();
    P( pa );

    // VtkOutput va;
    // pa.display_vtk( va );
    // va.save( "pa.vtk" );

    // pa.normalize();
    // P( pa );

    PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
    // pb.normalize();
    P( pb );

    // VtkOutput vb;
    // pb.display_vtk( vb );
    // vb.save( "pb.vtk" );

    PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
    P( pc );
    pc.normalize();
    P( pc );

    // VtkOutput vc;
    // pc.display_vtk( vc );
    // vc.save( "pc.vtk" );
}

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

// TEST_CASE( "PolyCon 3D spec", "" ) {
//     constexpr int nb_dims = 3;
//     using Scalar = double;
//     using Point = Vec<Scalar,nb_dims>;

//     // Affine functions:
//     //   -0.1641791044780048  +0.0597014925369581  +0.2025586353938458  -0.1582089552243079
//     //   +5.0000000000000000  -5.7500000000007949  +6.7499999999998854  +4.4249999999999199
//     //   +5.0000000000000000  +8.6666666666669698  +8.8095238095238528  +5.8666666666666965
//     // Boundaries:
//     //   -0.9949366763261821  -0.0710669054518706  -0.0710669054518697  -0.0497468338163088
//     //   +0.0000000000000000  -0.7071067811865476  +0.7071067811865476  +0.4949747468305832
//     //   +0.0000000000000000  -0.0000000000000005  -1.0000000000000000  +0.0000000000000000
//     //   +0.0000000000000000  +0.7071067811865476  +0.7071067811865476  +0.4949747468305832

//     Vec<Point> fun_dirs{
//         { -0.1641791044776095, +0.0597014925373079, +0.2025586353944587 },
//         { +5.0000000000000000, -5.7500000000000027, +6.7500000000000009 },
//         { +5.0000000000000000, +8.6666666666666625, +8.8095238095238084 },
//     };
//     Vec<Scalar> fun_offs{
//         -0.1582089552238816,
//         +4.4249999999999998,
//         +5.8666666666666654
//     };
//     Vec<Point> bnd_dirs{
//         { -0.9949366763261820, -0.0710669054518710, -0.0710669054518700 },
//         { +0.0000000000000000, -0.7071067811865477, +0.7071067811865474 },
//         { +0.0000000000000000, +0.0000000000000000, -1.0000000000000000 },
//         { +0.0000000000000000, +0.7071067811865476, +0.7071067811865476 },
//      };
//     Vec<Scalar> bnd_offs{
//         -0.0497468338163090,
//         +0.4949747468305832,
//         +0.0000000000000004,
//         +0.4949747468305833,
//     };

//     PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     P( pa );

//     VtkOutput va;
//     pa.display_vtk( va );
//     va.save( "pa.vtk" );

//     P( pa.legendre_transform() );
// }

// TEST_CASE( "PolyCon coinc", "" ) {
//     constexpr int nb_dims = 2;
//     using Scalar = double;

//     using Point = Vec<Scalar,nb_dims>;

//     Vec<Point> fun_dirs{ { -1, 0 }, { +1, 0 }, { 0, -1 }, { 0, +1 } };
//     Vec<Scalar> fun_offs{ 0.1, 0, 0, 0 };

//     Vec<Point> bnd_dirs{
//         { +1., 0. }, { -1., 0. },
//         { 0., +1. }, { 0., -1. },
//     };
//     Vec<Scalar> bnd_offs{ 5., 5., 5., 5. };

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
