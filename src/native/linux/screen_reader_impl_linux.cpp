#include "screen_reader_impl_linux.h"
#include "vwidget_generator.h"
#include <cassert>
#include <stdexcept>
#include <string>

namespace screen_reader {
std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
  atspi_init();
  AtspiAccessible *desktop = atspi_get_desktop(0);
  assert(desktop != nullptr && "Desktop does not exist");
  AtspiAccessible *target_node = findAtspiAccessibleByPID(desktop, pid);

  if (target_node == nullptr) {
    throw std::runtime_error("Cannot find PID");
  }

  std::shared_ptr<VirtualRootWidget> widget_tree =
      generator::GenerateVWidgetTree(target_node);

  return widget_tree;
}

AtspiAccessible *
ScreenReaderImpl::findAtspiAccessibleByPID(AtspiAccessible *node,
                                           const std::string &pid) const {
  if (node == nullptr) {
    return nullptr;
  }
  if (std::to_string(atspi_accessible_get_process_id(node, nullptr)) == pid) {
    return node;
  }

  size_t num_children = atspi_accessible_get_child_count(node, nullptr);
  for (size_t i = 0; i < num_children; i++) {
    AtspiAccessible *child = findAtspiAccessibleByPID(
        atspi_accessible_get_child_at_index(node, i, nullptr), pid);
    if (child != nullptr) {
      return child;
    }
  }
  return nullptr;
}

std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
  throw std::logic_error("Not yet implemented");
  return nullptr;
}

std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByClassName(
    const std::string &className) const {
  throw std::logic_error("Not yet implemented");
  return nullptr;
}
} // namespace screen_reader