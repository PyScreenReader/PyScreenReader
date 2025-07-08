#include "include/vwidget/widgets/virtual_text_input_widget.h"

VirtualTextInputWidget::VirtualTextInputWidget() : VirtualWidget("VirtualTextInputWidget") {}


#if defined(WIN_OS)
VirtualTextInputWidget::VirtualTextInputWidget(IUIAutomationElement* element)
    : VirtualWidget(element), insertion_point_(0), is_text_field_(false) {}
#endif