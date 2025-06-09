#include "include/vwidget/virtual_widget.h"

#include <utility>

void VirtualWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
  children_.emplace_back(child);
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetChild(int index) {
  return children_.at(index);
}

VirtualWidget::VirtualWidget(std::string widget_name) : widget_name_(std::move(widget_name)) {}
