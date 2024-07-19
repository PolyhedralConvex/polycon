#include <PowerDiagram/Cell.h>
#include "catch_main.h"

TEST_CASE( "Cell", "" ) {
    constexpr int nb_dims = 2;
    using Scalar = double;
    using C = Cell<Scalar,nb_dims>;

    C cell;
    cell.make_init_simplex( { -10, -10 }, { +10, +10 } );
    cell.cut( C::Point{ -1, 0 }, 1, 0 );
    cell.cut( C::Point{ +1, 0 }, 1, 1 );
    cell.cut( C::Point{ 0, -1 }, 1, 2 );
    cell.cut( C::Point{ 0, +1 }, 1, 3 );
    P( cell );
    P( cell.measure() );
}
