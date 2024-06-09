// cppimport
#include <pybind11/pybind11.h>

namespace py = pybind11;

int square( int x ) {
    return x * x + 8;
}

PYBIND11_MODULE(polycon_bindings, m) {
    m.def("square", &square);
}

/*
<%
setup_pybind11(cfg)
%>
*/
