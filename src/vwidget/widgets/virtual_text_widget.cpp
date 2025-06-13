#include "include/vwidget/widgets/virtual_text_widget.h"

VirtualTextWidget::VirtualTextWidget() : VirtualWidget("VirtualTextWidget") {}


#if defined(WIN_OS)
VirtualTextWidget::VirtualTextWidget(IUIAutomationElement* element)
    : VirtualWidget(element) {}
#endif