#include "include/vwidget/virtual_widget.h"

#include <sstream>
#include <iostream>

#include <ostream>
#include <utility>

VirtualWidget::VirtualWidget(std::string widget_name) : widget_name_(std::move(widget_name)) {}

#if defined(WIN_OS)
VirtualWidget::VirtualWidget(IUIAutomationElement* element) {
  RECT rect;
  HRESULT hresult = element->get_CurrentBoundingRectangle(&rect);
  if (SUCCEEDED(hresult)) {
    std::cout << "LEFT" << rect.left << " TOP" << rect.top << '\n';
  }
}
#endif


void VirtualWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
  children_.emplace_back(child);
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetChild(int index) const {
  return children_.at(index);
}

std::string VirtualWidget::ToString() const {
  std::ostringstream oss;
  oss << "{"
      << GetWidgetName()
      << ", title=" << GetTitleText()
      << ", help=" << GetHelpText()
      << ", x=" << GetX()
      << ", y=" << GetY()
      << ", width=" << GetWidth()
      << ", height=" << GetHeight()
      << ", visible=" << (IsVisible() ? "true" : "false")
      << "}";
  return oss.str();
}
