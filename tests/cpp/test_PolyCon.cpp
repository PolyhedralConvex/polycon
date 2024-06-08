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

//     PolyCon<Scalar,nb_dims> pl = pc.legendre_transform();
// }

TEST_CASE( "PolyCon 2D", "" ) {
    constexpr int nb_dims = 2;
    using Scalar = double;

    using Point = Vec<Scalar,nb_dims>;

    Vec<Point> fun_dirs{ { 1., 0. }, { 0., -0.7 }, { 0., +0.7 } };
    Vec<Scalar> fun_offs{ 0, 0, 0 };

    Vec<Point> bnd_dirs{};
    Vec<Scalar> bnd_offs{};

    PolyCon<Scalar,nb_dims> pc( fun_dirs, fun_offs, bnd_dirs, bnd_offs );

    VtkOutput vo;
    pc.display_vtk( vo );
    vo.save( "pc.vtk" );

    PolyCon<Scalar,nb_dims> pl = pc.legendre_transform();
}
