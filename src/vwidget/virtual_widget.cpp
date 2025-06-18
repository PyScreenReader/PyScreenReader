#include "include/vwidget/virtual_widget.h"

#include <utility>

#if defined(WIN_OS)
#include <uiautomationclient.h>

VirtualWidget::VirtualWidget(IUIAutomationElement* element) {
  RECT* rect;
  HRESULT hresult = element->get_CurrentBoundingRectangle(rect);
  if (SUCCEEDED(hresult)) {
  }
}
#endif


void VirtualWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
  children_.emplace_back(child);
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetChild(int index) {
  return children_.at(index);
}

std::vector<std::shared_ptr<VirtualWidget>> &VirtualWidget::GetChildren() {
  return children_;
}

VirtualWidget::VirtualWidget(std::string widget_name) : widget_name_(std::move(widget_name)) {}
