#include "include/vwidget/widgets/virtual_window_widget.h"

VirtualWindowWidget::VirtualWindowWidget()
    : VirtualWidget("VirtualWindowWidget"), is_modal_(false) {}

#if defined(WIN_OS)
VirtualWindowWidget::VirtualWindowWidget(IUIAutomationElement* element)
    : VirtualWidget(element), is_modal_(false) {}
#endif