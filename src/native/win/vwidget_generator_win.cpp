#include "src/native/win/vwidget_generator_win.h"

#include <comutil.h>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>

namespace vwidget_generator {
std::shared_ptr<VirtualWidget> GenerateVWidgetTree(IUIAutomationElement* root_element,
                                                   IUIAutomationTreeWalker* tree_walker) {
  auto root = std::make_shared<VirtualWindowWidget>();
  std::queue<std::pair<std::shared_ptr<VirtualWidget>, IUIAutomationElement*>> queue;
  queue.emplace(root, root_element);
  HRESULT hresult = S_OK;
  while (!queue.empty()) {
    // This is the first child of the clade
    auto [parent_vwidget, curr] = queue.front();
    queue.pop();

    std::shared_ptr<VirtualWidget> curr_vwidget = nullptr;
    IUIAutomationElement* current_element = curr;
    IUIAutomationElement* first_child_element = nullptr;
    while (current_element) {
      // Check next sibling, add their first child to queue and bind
      // parent/child
      curr_vwidget = MapToVWidget(current_element);
      curr_vwidget->SetParent(parent_vwidget);
      parent_vwidget->AddChild(curr_vwidget);
      tree_walker->GetFirstChildElement(current_element, &first_child_element);
      if (first_child_element) {
        queue.emplace(curr_vwidget, first_child_element);
      }
      hresult = tree_walker->GetNextSiblingElement(current_element, &current_element);
      // TODO: Use DCHECK_EQ in #56
      // if (FAILED(hresult))
      //   throw std::runtime_error("Failed GetNextSiblingElement");
    }
  }
  return root;
}

std::shared_ptr<VirtualWidget> MapToVWidget(IUIAutomationElement* element) {
  CONTROLTYPEID type_id;
  element->get_CurrentControlType(&type_id);
  std::shared_ptr<VirtualWidget> result = nullptr;
  auto iterator = kRoleWidgetMap.find(type_id);
  if (iterator == kRoleWidgetMap.end()) {
    result = vwidget_factory::CreateWidget<VirtualUnknownWidget>(element);
  } else {
    result = iterator->second(element);
  }

  return result;
}
}  // namespace vwidget_generator
