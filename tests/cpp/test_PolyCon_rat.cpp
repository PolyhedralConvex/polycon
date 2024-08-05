#include <PowerDiagram/support/Rational.h>
#include <polycon/PolyCon.h>
#include "catch_main.h"


// TEST_CASE( "PolyCon rat", "" ) {
// constexpr int nb_dims = 3;
// using Scalar = Rational;
// using Point = Vec<Scalar,nb_dims>;
//     Vec<Point> fun_dirs{
//         { -5, -5, -5 },
//         { -5, -5,  5 },
//         { -5,  5, -5 },
//         { -5,  5,  5 },
//         {  5, -5, -5 },
//         {  5, -5,  5 },
//         {  5,  5, -5 },
//         {  5,  5,  5 }
//     };
//     Vec<Scalar> fun_offs{
//         -5, -5, -4, -4, 4, 4, 5, 5
//     };

//     Vec<Point> bnd_dirs{ };
//     Vec<Scalar> bnd_offs{ };

//     PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );
//     pa.normalize();
//     P( pa );

//     PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
//     pb.normalize();
//     P( pb );

//     PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
//     pc.normalize();
//     P( pc );
// }

TEST_CASE( "PolyCon rat red dim", "" ) {
    constexpr int nb_dims = 2;
    using Scalar = Rational;
    using Point = Vec<Scalar,nb_dims>;

    Vec<Point> fun_dirs{
        { -1, 0 },
        { +0, 0 },
        { +1, 0 },
    };
    Vec<Scalar> fun_offs{
        0, 0, 1
    };

    Vec<Point> bnd_dirs{ };
    Vec<Scalar> bnd_offs{ };

    PolyCon<Scalar,nb_dims> pa( fun_dirs, fun_offs, bnd_dirs, bnd_offs );

    VtkOutput vo;
    pa.display_vtk( vo );
    vo.save( "pa.vtk" );

    pa.normalize();
    P( pa );

    PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
    // pb.normalize();
    P( pb );

    // PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
    // pc.normalize();
    // P( pc );
}

