from matplotlib import pyplot
from polycon import PolyCon

def test_1D():
    afds_0 = [ [ -1.0 ], [ +0.1 ], [ +0.7 ] ]
    afos_0 = [ 0.1, 0.2, 2.0 ]
    bnds_0 = []
    bnos_0 = []

    pc = PolyCon( afds_0, afos_0, bnds_0, bnos_0 )

    afds_1 = [ [ -0.8 ], [ +0.6 ] ]
    afos_1 = [ 0, 0.0 ]
    bnds_1 = []
    bnos_1 = []

    pd = PolyCon( afds_1, afos_1, bnds_1, bnos_1 )

    pe = pc + pd

    pc.plot( "black" )
    pd.plot( "blue" )
    pe.plot( "red" )

    # pd = pc.legendre_transform()
    # pd.plot( "blue" )

    pyplot.show()


def test_2D():
    afds = [ [ 1, 0.1 ], [ 0.1, -0.7 ], [ 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2 ]
    bnds = []
    bnos = []

    pc = PolyCon( afds, afos, bnds, bnos )
    # pc.write_vtk( "p2.vtk" )
    pc.plot()

def test_3D():
    afds = [ [ 1, 0.1, 0 ], [ 0.1, -0.7, 0 ], [ 0, +0.7, 0 ], [ 0, 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2, 0.3 ]
    bnds = []
    bnos = []

    pc = PolyCon( afds, afos, bnds, bnos )
    pc.write_vtk( "p3.vtk" )

test_1D()
# test_2D()
# test_3D()
