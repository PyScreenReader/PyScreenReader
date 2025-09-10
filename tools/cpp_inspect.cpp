/**
 * PyScreenReader - Inspect C++
 *
 * Run ScreenReader C++ implementation directly
 *
 * """
 * bazel run //tools:cpp_inspect -- --pid=[pid#]
 * """
 */

#include <cxxopts.hpp>

#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <utility>

#include "include/api/screen_reader.h"
#include "include/vwidget/virtual_widget.h"

void PrintTree(const std::shared_ptr<VirtualWidget>& root) {
  std::stack<std::pair<std::shared_ptr<VirtualWidget>, int>> node_stack;
  node_stack.emplace(root, 0);

  while (!node_stack.empty()) {
    auto& [curr_node, indent] = node_stack.top();
    node_stack.pop();

    if (!curr_node) {
      node_stack.pop();
      continue;
    }

    std::cout << std::string(indent * 2, ' ');
    std::cout << curr_node->ToString() << std::endl;

    for (const auto& child : curr_node->GetChildren()) {
      node_stack.emplace(child, indent + 1);
    }
  }
}

int main(int argc, char* argv[]) {
  cxxopts::Options options("PyScreenReader - Inspect C++",
                           "Run ScreenReader C++ implementation directly");

  options.add_options()("p,pid", "pid number of the program", cxxopts::value<int>());

  auto result = options.parse(argc, argv);

  if (result.count("pid") == 0) {
    std::cout << options.help() << '\n';
    return 1;
  }

  const pid_t pid = result["pid"].as<pid_t>();
  std::cout << "Running cpp_inspect on PID: " << pid << '\n';

  ScreenReader screen_reader;
  std::shared_ptr<VirtualWidget> root = screen_reader.GetVirtualWidgetTreeByPID(pid);

  PrintTree(root);
  return 0;
}
