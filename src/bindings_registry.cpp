#include "bindings_registry.h"
#include <vector>

std::vector<BindingFunc>& GetRegistry() {
    static std::vector<BindingFunc> registry;
    return registry;
}

void BindingsRegistry::add(BindingFunc func) {
    GetRegistry().push_back(func);
}

void BindingsRegistry::runAll(py::module_& m) {
    for (auto& func : GetRegistry()) {
        func(m);
    }
}