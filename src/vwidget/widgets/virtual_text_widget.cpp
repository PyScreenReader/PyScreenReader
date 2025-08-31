#include <utility>

#include "include/vwidget/widgets/virtual_text_widget.h"

VirtualTextWidget::VirtualTextWidget() : VirtualWidget("VirtualTextWidget") {}
VirtualTextWidget::VirtualTextWidget(std::string widget_name) : VirtualWidget(std::move(widget_name)) {}

