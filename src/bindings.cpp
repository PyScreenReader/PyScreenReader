#include <pybind11/pybind11.h>

#include "vwidget/virtual_widget.h"
#include "bindings_registry.h"

namespace py = pybind11;

PYBIND11_MODULE(PyScreenReader, m) {
    BindingsRegistry::runAll(m);
}