#include "include/vwidget/widgets/virtual_button_widget.h"

VirtualButtonWidget::VirtualButtonWidget() : VirtualWidget("VirtualButtonWidget") {};

#if defined(WIN_OS)
VirtualButtonWidget::VirtualButtonWidget(IUIAutomationElement* element)
    : VirtualWidget(element) {}
#endif
