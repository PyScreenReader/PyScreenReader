#include "bindings_registry.h"

#include <algorithm>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <iostream>

std::unordered_map<std::string, BindingsRegistry::BindingFunc>& GetBindingFuncRegistry() {
  static std::unordered_map<std::string, BindingsRegistry::BindingFunc> binding_func_registry;
  return binding_func_registry;
}

std::unordered_map<std::string, std::set<std::string>>& GetDepRegistry() {
  static std::unordered_map<std::string, std::set<std::string>> dep_registry;
  return dep_registry;
}

void BindingsRegistry::Add(const std::string& name,
                           const BindingFunc& func,
                           const std::initializer_list<std::string>& deps) {
  auto& func_registry = GetBindingFuncRegistry();
  auto& dep_registry = GetDepRegistry();
  if (func_registry.find(name) != func_registry.end()) {
    throw std::invalid_argument(name +
                                " has been found in registry. Is it possible that bindings with "
                                "the same name has been registered multiple times?");
  }
  func_registry.emplace(name, func);
  dep_registry.emplace(name, std::set<std::string>(deps));
}

void BindingsRegistry::ValidateDependencies() {
  auto& dep_registry = GetDepRegistry();
  auto& func_registry = GetBindingFuncRegistry();

  for (const auto& [node, adjs] : dep_registry) {
    for (const auto& adj : adjs) {
      if (dep_registry.find(adj) == dep_registry.end()) {
        throw std::invalid_argument(adj +
                                    " is not defined in dependency graph, but is referenced.");
      }
      if (func_registry.find(adj) == func_registry.end()) {
        throw std::invalid_argument(adj +
                                    " is not given a binding function to call, but is referenced.");
      }
    }
  }
}

void BindingsRegistry::PrintDepRegistry() {
  auto& dep_registry = GetDepRegistry();

  std::cout << "=== DEBUG: Dependency Graph ===\n";
  for (const auto& [node, adjs] : dep_registry) {
    std::cout << "  " << node << " -> [ ";
    for (const auto& adj : adjs) {
      std::cout << adj << " ";
    }
    std::cout << "]\n";
  }
  std::cout << "========================\n";
}

void BindingsRegistry::RunAll(py::module_& m) {
// TODO: guard this with debug flag / integrate glog
  PrintDepRegistry();
  ValidateDependencies();

  auto& dep_registry = GetDepRegistry();
  auto& func_registry = GetBindingFuncRegistry();

  // reverse the graph direction, so we start with dependencies
  std::unordered_map<std::string, std::set<std::string>> reversed_adj;
  for (const auto& [node, deps] : dep_registry) {
    for (const auto& dep : deps) {
      reversed_adj[dep].insert(node);
    }
  }

  // Use topological sort to bind classes in sequence
  std::unordered_map<std::string, int> indegree_map;
  for (const auto& [node, adjs] : reversed_adj) {
    for (const auto& adj : adjs) {
      indegree_map[adj]++;
    }
  }

  std::queue<std::string> queue;
  for (const auto& [node, adjs] : dep_registry) {
    if (indegree_map.find(node) == indegree_map.end()) {
      indegree_map[node] = 0;
      queue.emplace(node);
    }
  }

  while (!queue.empty()) {
    const std::string& curr_node = queue.front();
    const std::set<std::string>& adjs = reversed_adj[curr_node];
    // bind C++ definition to python
    func_registry[curr_node](m);
    queue.pop();
    for (const auto& adj : adjs) {
      indegree_map[adj]--;
      if (indegree_map[adj] == 0) {
        queue.emplace(adj);
      }
    }
  }

  // check if all the nodes are processed. If not, there must be a cycle in the
  // graph
  if (std::any_of(indegree_map.begin(), indegree_map.end(), [](auto& p) { return p.second != 0; })) {
    throw std::invalid_argument("Cycles might exist in the dependency graph! Cannot bind.");
  }
}
