from matplotlib import pyplot
from polycon import PolyCon
import numpy as np

def test_1D():
    # afds_0 = [ [ -1.0 ], [ +0.1 ], [ +0.7 ] ]
    # afos_0 = [ 0.1, 0.2, 2.0 ]
    # bnds_0 = [ [ 1 ] ]
    # bnos_0 = [ 2 ]

    # pc = PolyCon( afds_0, afos_0, bnds_0, bnos_0 )
    # print( pc )

    # # s = pc.__repr__()

    # pd = PolyCon.from_sym_repr( 'max(3*a+2*b-1, 4*a-b+3,7*a-3*b+9)', [ 'a+1 <= 0 ', 'b >= 1' ] )
    # print( pd )

    # afds_1 = [ [ -0.8 ], [ +0.6 ] ]
    # afos_1 = [ 0, 0.0 ]
    # bnds_1 = []
    # bnos_1 = []

    # pd = PolyCon( afds_1, afos_1, bnds_1, bnos_1 )

    # pe = pc + pd

    # pc.plot( "black" )
    # pd.plot( "blue" )
    # pe.plot( "red" )

    # # pd = pc.legendre_transform()
    # # pd.plot( "blue" )

    # pyplot.show()

    q = PolyCon([ [ -1. ], [ +2 ], [ 3 ] ], [ 0 , -1 , +1 ] ,[ [ -1. ], [ +1. ] ],[ 3, 3 ] )
    #s = p+q
    #s.value([[-1/3],[0],[1],[2]])
    #p.plot(color='b',show=False)
    q.plot()


def test_2D():
    afds = [ [ 1, 0.1 ], [ 0.1, -0.7 ], [ 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2 ]
    bnds = [ [ 1, 0 ] ]
    bnos = [ 5 ]

    pc = PolyCon( afds, afos, bnds, bnos )
    pc.write_vtk( "p2.vtk" )

    # pc.plot()
    print( pc )
    print( pc.__repr__( table = True ) )

def test_3D():
    afds = [ [ 1, 0.1, 0 ], [ 0.1, -0.7, 0 ], [ 0, +0.7, 0 ], [ 0, 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2, 0.3 ]
    bnds = [ [ 1, 0, 0 ] ]
    bnos = [ 5 ]

    pc = PolyCon( afds, afos, bnds, bnos )
    pc.write_vtk( "p3.vtk" )

    print( "\npc =======================================" )
    print( pc.normalized( 1e-6 ) )

    pd = pc.legendre_transform()
    print( "\npd =======================================" )
    print( pd.normalized( 1e-6 ) )
    pd.write_vtk( "pd.vtk" )

    pe = pd.legendre_transform()
    print( "\npe =======================================" )
    print( pe.normalized( 1e-6 ) )

# def test_rat():
#     from fractions import Fraction
#     afds_0 = [ [ -Fraction( 1, 1 ) ], [ +Fraction( 1, 10 ) ], [ +Fraction( 7, 10 ) ] ]
#     afos_0 = [ Fraction( 1, 10 ), Fraction( 2, 10 ), 2 ]
#     bnds_0 = []
#     bnos_0 = []

#     pc = PolyCon( afds_0, afos_0, bnds_0, bnos_0 )
#     pc.plot()

    # from polycon.lib.type_promote import type_name_item_of
 
    # a = np.array( [ 1 ] )
    # print( type_name_item_of( a ) )
    # print( type_name_item_of( [ 1, 1.5 ] ) )
    # print( type_name_item_of( [[ 1, Fraction( 1, 2 ) ]] ) )

    # afds = [ 
    #     [ 1                , +Fraction( 1, 10 ), 0                  ], 
    #     [ Fraction( 1, 10 ), -Fraction( 7, 10 ), 0                  ], 
    #     [ 0                , +Fraction( 7, 10 ), 0                  ], 
    #     [ 0                , 0                 , +Fraction( 7, 10 ) ]
    # ]
    # afos = [ 0, Fraction( 1, 10 ), Fraction( 2, 10 ), Fraction( 3, 10 ) ]
    # bnds = [ [ 1, 0, 0 ] ]
    # bnos = [ 5 ]

    # pc = PolyCon( afds, afos, bnds, bnos )
    # pc.write_vtk( "p3.vtk" )

    # print( "\npc =======================================" )
    # print( pc.normalized() )

    # pd = pc.legendre_transform()
    # print( "\npd =======================================" )
    # print( pd.normalized() )
    # # pd.write_vtk( "pd.vtk" )

    # pe = pd.legendre_transform()
    # print( "\npe =======================================" )
    # print( pe.normalized() )

# test_rat()

# test_1D()
# test_2D()
# test_3D()

import polycon as pc
import numpy as np

u = pc.PolyCon.from_sym_repr( 'max( 2-2*x, 0, x-2 )' , [ 'x >= 0' ], verbose = 0 )
print( u.value_and_gradients( [ 1.0 ], 1e-6 ) )
print( u.value_and_gradients( [ 1.5 ], 1e-6 ) )
print( u.value_and_gradients( [ 2.0 ], 1e-6 ) )
u.plot()
