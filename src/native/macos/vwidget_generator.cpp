#include <queue>
#include <utility>
#include <optional>
#include <string>

#include "src/native/macos/utils/cf_utils.h"
#include "src/native/macos/vwidget_generator.h"
#include "src/native/macos/vwidget_factory.h"

std::shared_ptr<VirtualWidget> vwidget_generator::GenerateVWidgetTree(AXUIElementRef root_element) {
  if (!root_element)
    return nullptr;

  // each pair in the queue contains
  // [parent virtual widget of current AXUIElementRef, current AXUIElementRef]
  std::queue<std::pair<std::shared_ptr<VirtualWidget>, AXUIElementRef>> queue;
  queue.emplace(nullptr, root_element);

  std::shared_ptr<VirtualWidget> root = nullptr;

  while (!queue.empty()) {
    auto [parent_vwidget, curr] = queue.front();
    queue.pop();

    auto curr_vwidget = vwidget_generator::MapToVWidget(curr);

    // Connect nodes to form a tree
    if (parent_vwidget) {
      parent_vwidget->AddChild(curr_vwidget);
      curr_vwidget->SetParent(parent_vwidget);
    } else {
      // parent_vwidget is nullptr means the current node is the root
      root = curr_vwidget;
    }

    // Handle children of the current node
    std::optional<CFArrayRef> children_arr_opt = cf_utils::GetAttribute<CFArrayRef>(curr, kAXChildrenAttribute);
    if (!children_arr_opt.has_value())
      continue;

    CFArrayRef children_arr = children_arr_opt.value();
    const CFIndex children_count = CFArrayGetCount(children_arr);
    for (CFIndex i = 0; i < children_count; ++i) {
      const auto *child = static_cast<AXUIElementRef>(CFArrayGetValueAtIndex(children_arr, i));
      queue.emplace(curr_vwidget, child);
    }
//    CFRelease(children_arr);
  }
  return root;
}

std::shared_ptr<VirtualWidget> vwidget_generator::MapToVWidget(AXUIElementRef element) {
  std::optional<std::string> role_id_opt = cf_utils::GetAttribute<std::string>(element, kAXRoleAttribute);
  if (!role_id_opt.has_value()) {
    // Falls back to virtual unknown widget if fails to get role_id
    return vwidget_factory::CreateWidget<VirtualUnknownWidget>(element);
  }

  auto iter = vwidget_generator::kRoleWidgetMap.find(role_id_opt.value());
  if (iter != vwidget_generator::kRoleWidgetMap.end()) {
    return iter->second(element);
  }

  // Falls back to virtual unknown widget
  return vwidget_factory::CreateWidget<VirtualUnknownWidget>(element);
}
