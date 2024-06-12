// cppimport

#define POLYCON_DIM 1
#define POLYCON_SCALAR Rational
#include <PowerDiagram/support/Rational.h>

#include "polycon_bindings.h"

PYBIND11_MODULE(polycon_bindings_01_Rational, m) {
    fill_polycon_module( m, "PolyCon_01_Rational" );
}
    
/*
<%
import sys, os
sys.path.append( os.getcwd() + '/polycon/lib' )
from cppimport_cfg import cppimport_cfg
setup_pybind11( cfg )
cppimport_cfg( cfg )
%>
*/
        