#include <pybind11/pybind11.h>
#include "bindings_registry.h"

namespace py = pybind11;

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

PYBIND11_MODULE(PyScreenReader, m) {
  BindingsRegistry::RunAll(m);

// Inject version information
#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}