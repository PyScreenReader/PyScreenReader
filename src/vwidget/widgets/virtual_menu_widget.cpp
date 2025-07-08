#include "include/vwidget/widgets/virtual_menu_widget.h"

VirtualMenuWidget::VirtualMenuWidget() : VirtualWidget("VirtualMenuWidget") {}

#if defined(WIN_OS)
VirtualMenuWidget::VirtualMenuWidget(IUIAutomationElement* element)
    : VirtualWidget(element) {}
#endif