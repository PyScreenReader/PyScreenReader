#include "include/vwidget/widgets/virtual_unknown_widget.h"

VirtualUnknownWidget::VirtualUnknownWidget() : VirtualWidget("VirtualUnknownWidget") {}

#if defined(WIN_OS)
VirtualUnknownWidget::VirtualUnknownWidget(IUIAutomationElement* element)
    : VirtualWidget(element) {}
#endif