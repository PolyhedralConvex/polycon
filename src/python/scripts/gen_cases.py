for d in range( 1, 11 ):
    for t in [ 'FP64' ]:
        module = 'polycon_bindings_{:02}_{}'.format( d, t )
        filename = 'polycon/lib/{}.cpp'.format( module )
        class_name = 'PolyCon_{:02}_{}'.format( d, t )
        with open( filename, 'w' ) as f:
            f.write( f"""// cppimport

#define POLYCON_DIM { d }
#define POLYCON_SCALAR { t }
#include "polycon_bindings.h"

PYBIND11_MODULE({ module }, m) {{
    fill_polycon_module( m, "{ class_name }" );
}}

/*
<%
import sys, os
sys.path.append( os.getcwd() + '/polycon/lib' )
from cppimport_cfg import cppimport_cfg
setup_pybind11( cfg )
cppimport_cfg( cfg )
%>
*/
""" )