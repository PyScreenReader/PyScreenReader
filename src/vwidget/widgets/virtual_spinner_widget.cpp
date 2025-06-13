#include "include/vwidget/widgets/virtual_spinner_widget.h"

VirtualSpinnerWidget::VirtualSpinnerWidget() : NumericValueWidget("VirtualSpinnerWidget") {}

#if defined(WIN_OS)
VirtualSpinnerWidget::VirtualSpinnerWidget(IUIAutomationElement* element)
    : NumericValueWidget(element) {}
#endif