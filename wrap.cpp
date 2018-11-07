#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "funcs.h"
#include "trajectoire.h"

namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_PLUGIN(wrap) {
    py::module m("wrap", "pybind11 example plugin");
    m.def("simulate", &simulate);
    return m.ptr();
}
