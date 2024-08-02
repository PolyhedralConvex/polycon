#include <PowerDiagram/support/Rational.h>
#include <polycon/PolyCon.h>
#include "catch_main.h"

constexpr int nb_dims = 3;
using Scalar = Rational;
using Point = Vec<Scalar,nb_dims>;


TEST_CASE( "PolyCon rat", "" ) {
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

    PolyCon<Scalar,nb_dims> pb = pa.legendre_transform();
    pb.normalize();
    P( pb );

    PolyCon<Scalar,nb_dims> pc = pb.legendre_transform();
    pc.normalize();
    P( pc );
}

