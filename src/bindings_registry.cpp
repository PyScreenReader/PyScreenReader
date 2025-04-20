#include "bindings_registry.h"

#include <algorithm>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, BindingsRegistry::BindingFunc> &getBindingFuncRegistry() {
    static std::unordered_map<std::string, BindingsRegistry::BindingFunc> bindingFuncRegistry_;
    return bindingFuncRegistry_;
}

std::unordered_map<std::string, std::set<std::string>> &getDepRegistry() {
    static std::unordered_map<std::string, std::set<std::string>> depRegistry_;
    return depRegistry_;
}

void BindingsRegistry::add(const std::string &name, const BindingFunc& func, const std::initializer_list<std::string> &deps) {
    auto &funcRegistry = getBindingFuncRegistry();
    auto &depRegistry = getDepRegistry();
    if (funcRegistry.find(name) != funcRegistry.end()) {
        throw std::invalid_argument(name +
                                    " has been found in registry. Is it possible that bindings with the same name has been registered multiple times?");
    }
    funcRegistry.emplace(name, func);
    depRegistry.emplace(name, std::set<std::string>(deps));
}

void BindingsRegistry::validateDependencies() {
    auto &depRegistry = getDepRegistry();
    auto &funcRegistry = getBindingFuncRegistry();
    for (auto &[node, adjs]: depRegistry) {
        for (auto &adj: adjs) {
            if (depRegistry.find(adj) == depRegistry.end()) {
                throw std::invalid_argument(adj + " is not defined in dependency graph, but is referenced.");
            }
            if (funcRegistry.find(adj) == funcRegistry.end()) {
                throw std::invalid_argument(adj + " is not given a binding function to call, but is referenced.");
            }
        }
    }
}

void BindingsRegistry::runAll(py::module_ &m) {
    validateDependencies();

    auto &depRegistry = getDepRegistry();
    auto &funcRegistry = getBindingFuncRegistry();

    // reverse the graph direction, so we start with dependencies
    std::unordered_map<std::string, std::set<std::string>> reverseAdj;
    for (auto &[node, deps] : depRegistry) {
        for (const auto &dep : deps) {
            reverseAdj[dep].insert(node);
        }
    }

    // Use topological sort to bind classes in sequence
    std::unordered_map<std::string, int> indegreeMap;
    for (auto &[node, adjs]: reverseAdj) {
        for (auto &adj: adjs) {
            indegreeMap[adj]++;
        }
    }

    std::queue<std::string> q;
    for (auto &[node, adjs]: depRegistry) {
        if (indegreeMap.find(node) == indegreeMap.end()) {
            indegreeMap[node] = 0;
            q.emplace(node);
        }
    }

    while (!q.empty()) {
        const std::string &currNode = q.front();
        const std::set<std::string> &adjs = reverseAdj[currNode];
        // bind C++ definition to python
        funcRegistry[currNode](m);
        q.pop();
        for (auto &adj: adjs) {
            indegreeMap[adj]--;
            if (indegreeMap[adj] == 0) {
                q.emplace(adj);
            }
        }
    }

    // check if all the nodes are processed. If not, there must be a cycle in the graph
    if (std::any_of(indegreeMap.begin(), indegreeMap.end(), [](auto &p) { return p.second != 0; })) {
        throw std::invalid_argument("Cycles might exist in the dependency graph! Cannot bind.");
    }
}