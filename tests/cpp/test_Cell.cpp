// #include <PowerDiagram/support/boost_mpf.h>
#include <PowerDiagram/Cell.h>
#include "catch_main.h"

using Scalar = double;

TEST_CASE( "Cell surface triangle", "" ) {
    Cell<Scalar,2> pa;
    pa.make_init_simplex( { -10, -10 }, { +10, +10 } );

    pa.cut( { 1 ,  1 }, 1, 11 );
    pa.cut( { -1,  0 }, 0, 12 );
    pa.cut( { 0 , -1 }, 0, 13 );

    CHECK_REPR( pa.measure(), Scalar( 1 ) / 2 );
}

TEST_CASE( "Cell surface square", "" ) {
    Cell<Scalar,2> pa;
    pa.make_init_simplex( { -10, -10 }, { +10, +10 } );

    pa.cut( { +1,  0 }, 1, 12 );
    pa.cut( { 0 , +1 }, 1, 13 );
    pa.cut( { -1,  0 }, 0, 15 );
    pa.cut( { 0 , -1 }, 0, 16 );

    CHECK_REPR( pa.measure(), Scalar( 1 ) );
}

TEST_CASE( "Cell volume tetra", "" ) {
    Cell<Scalar,3> pa;
    pa.make_init_simplex( { -10, -10, -10 }, { +10, +10, +10 } );

    pa.cut( { 1 ,  1,  1 }, 1, 11 );
    pa.cut( { -1,  0,  0 }, 0, 12 );
    pa.cut( { 0 , -1,  0 }, 0, 13 );
    pa.cut( { 0 ,  0, -1 }, 0, 13 );

    CHECK_REPR( pa.measure(), Scalar( 1 ) / 6 );
}

TEST_CASE( "Cell volume cube", "" ) {
    Cell<Scalar,3> pa;
    pa.make_init_simplex( { -10, -10, -10 }, { +10, +10, +10 } );

    pa.cut( { +1,  0,  0 }, 1, 12 );
    pa.cut( { 0 , +1,  0 }, 1, 13 );
    pa.cut( { 0 ,  0, +1 }, 1, 14 );
    pa.cut( { -1,  0,  0 }, 0, 15 );
    pa.cut( { 0 , -1,  0 }, 0, 16 );
    pa.cut( { 0 ,  0, -1 }, 0, 17 );

    CHECK_REPR( pa.measure(), Scalar( 1 ) );
}
