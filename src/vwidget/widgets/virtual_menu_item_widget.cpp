#include "include/vwidget/widgets/virtual_menu_item_widget.h"

VirtualMenuItemWidget::VirtualMenuItemWidget() : VirtualWidget("VirtualMenuItemWidget") {}

#if defined(WIN_OS)
VirtualMenuItemWidget::VirtualMenuItemWidget(IUIAutomationElement* element)
    : VirtualWidget(element) {}
#endif