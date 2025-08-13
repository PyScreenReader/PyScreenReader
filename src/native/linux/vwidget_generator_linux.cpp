#include <cassert>
#include <glib-object.h>
#include <queue>
#include <iostream>

#include "src/native/linux/vwidget_generator_linux.h"
#include "src/native/linux/utils/atspi_utils.h"

std::shared_ptr<VirtualWidget>
vwidget_generator::GenerateVWidgetTree(AtspiAccessible *root_element) {
  if (!root_element)
    return nullptr;

  g_object_ref(root_element);

  std::queue<std::pair<std::shared_ptr<VirtualWidget>, AtspiAccessible*>> queue;
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

    std::optional<unsigned int> child_count_opt = atspi_utils::GetChildrenCount(curr);
    if (!child_count_opt.has_value())
      continue;

    for (unsigned int i = 0; i < child_count_opt.value(); i++) {
      auto child_opt = atspi_utils::GetChildAtIndex(curr, i);
      if (!child_opt.has_value())
        continue;

      queue.emplace(curr_vwidget, child_opt.value());
    }
    g_object_unref(curr);
  }
  return root;
}

std::shared_ptr<VirtualWidget> vwidget_generator::MapToVWidget(AtspiAccessible *element) {
  auto elem_role_opt = atspi_utils::GetRole(element);

  if (!elem_role_opt.has_value())
    return vwidget_factory::CreateWidget<VirtualUnknownWidget>(element);

  std::shared_ptr<VirtualWidget> vwidget_element;
  auto iter = vwidget_generator::kRoleWidgetMap.find(elem_role_opt.value());
  if (iter != vwidget_generator::kRoleWidgetMap.end()) {
    vwidget_element = iter->second(element);
  } else {
    auto elem_role_name_opt = atspi_utils::GetRoleName(element);

    if (elem_role_name_opt.has_value()) {
       std::cerr << "Unrecognized role name: " << elem_role_name_opt.value() << std::endl;
    } else {
       std::cerr << "Unrecognized role id: " << elem_role_opt.value() << std::endl;
    }

    vwidget_element = vwidget_factory::CreateWidget<VirtualUnknownWidget>(element);
  }

  return vwidget_element;
}

