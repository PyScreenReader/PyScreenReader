#include <utility>

#include <sstream>
#include "include/vwidget/widgets/virtual_text_widget.h"

#include <ostream>

VirtualTextWidget::VirtualTextWidget() : VirtualWidget("VirtualTextWidget") {}
VirtualTextWidget::VirtualTextWidget(std::string widget_name)
    : VirtualWidget(std::move(widget_name)) {}

std::string VirtualTextWidget::ToString() const {
  std::ostringstream oss;
  oss << "{" << GetWidgetName() << ", title=" << GetTitleText() << ", help=" << GetHelpText()
      << ", x=" << GetX() << ", y=" << GetY() << ", width=" << GetWidth()
      << ", height=" << GetHeight() << ", visible=" << (IsVisible() ? "true" : "false")
      << ", selected_text=" << GetSelectedText() << "}";
  return oss.str();
}