#pragma once

#include "vwidget/widgets/virtual_menu_item_widget.h"

std::string VirtualMenuItemWidget::getWidgetName() {
    return "VirtualMenuItemWidget";
}

bool VirtualMenuItemWidget::isClickable() {
    return true;
}
