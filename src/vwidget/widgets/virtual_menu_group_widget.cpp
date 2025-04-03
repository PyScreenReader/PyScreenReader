#pragma once

#include "vwidget/widgets/virtual_menu_group_widget.h"

std::string VirtualMenuGroupWidget::getWidgetName() {
    return "VirtualMenuGroupWidget";
}

bool VirtualMenuGroupWidget::isClickable() {
    return false;
}
