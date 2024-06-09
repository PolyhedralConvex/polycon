from polycon import PolyCon

def test_2D():
    afds = [ [ 1, 0.1 ], [ 0.1, -0.7 ], [ 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2 ]
    bnds = []
    bnos = []

    pc = PolyCon( afds, afos, bnds, bnos )
    pc.write_vtk( "p2.vtk" )

def test_3D():
    afds = [ [ 1, 0.1, 0 ], [ 0.1, -0.7, 0 ], [ 0, +0.7, 0 ], [ 0, 0, +0.7 ] ]
    afos = [ 0, 0.1, 0.2, 0.3 ]
    bnds = []
    bnos = []

    pc = PolyCon( afds, afos, bnds, bnos )
    pc.write_vtk( "p3.vtk" )

test_2D()
test_3D()
