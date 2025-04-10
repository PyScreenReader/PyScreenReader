#pragma once

#include <vector>
#include <functional>
#include <pybind11/pybind11.h>
#include <set>
#include <map>
#include <memory>

namespace py = pybind11;

class BindingsRegistry {
public:
    /**
     * BindingFunc is a function that consumes a PyBinding module, and perform bindings to this module
     */
    using BindingFunc = std::function<void(py::module_ &)>;

    /**
     * @brief Registers a binding function along with its dependencies.
     *
     * This method adds a new binding function to the registry, associating it with a name
     * and a list of dependencies (other bindings that must be run before this one).
     *
     * @param name The unique name identifying the binding. Must not conflict with existing names.
     * @param func The function that performs the actual binding to Python (e.g., class/module binding).
     * @param deps A list of names this binding depends on. These dependencies must be registered as well.
     *
     * @throws std::invalid_argument if the name has already been registered.
     */
    static void add(const std::string &name, const BindingFunc& func, const std::initializer_list<std::string> &deps);

    /**
     * @brief Executes all registered binding functions in topological order.
     *
     * This method checks that all dependencies are valid, then performs a topological sort
     * to ensure that bindings are run in a correct order (i.e., all dependencies are bound before the dependent).
     * It invokes each binding function, passing the given Python module as a parameter.
     *
     * @param m The pybind11 module into which all bindings will be defined.
     *
     * @throws std::invalid_argument if a dependency is undefined or if there is a cycle in the dependency graph.
     */
    static void runAll(py::module_ &m);

private:
    /**
     * @brief Validates that all registered dependencies are defined and callable.
     *
     * This method checks the dependency graph to ensure:
     * 1. Every dependency listed is also registered.
     * 2. Every dependency has an associated binding function.
     *
     * Should be called before executing bindings to prevent runtime errors due to
     * missing or undefined dependencies.
     *
     * @throws std::invalid_argument if a dependency is referenced but never defined or lacks a binding function.
     */
    static void validateDependencies();
};

#define REGISTER_BINDING(name, func, ...) \
namespace { \
struct AutoRegister_##func { \
    AutoRegister_##func() { \
        std::initializer_list<std::string> deps = {__VA_ARGS__}; \
        BindingsRegistry::add(name, func, deps); \
    } \
}; \
} \
static AutoRegister_##func _autoRegister_##func;