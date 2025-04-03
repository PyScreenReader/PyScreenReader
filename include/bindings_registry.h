#pragma once

#include <vector>
#include <functional>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using BindingFunc = std::function<void(py::module_&)>;

class BindingsRegistry {
public:
    static void add(BindingFunc func);
    static void runAll(py::module_& m);
};

#define REGISTER_BINDING(func) \
namespace { \
struct AutoRegister_##func { \
    AutoRegister_##func() { \
        BindingsRegistry::add(func); \
    } \
}; \
} \
static AutoRegister_##func _autoRegister_##func;