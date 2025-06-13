#include "include/vwidget/widgets/virtual_progress_bar_widget.h"

VirtualProgressBarWidget::VirtualProgressBarWidget()
    : NumericValueWidget("VirtualProgressBarWidget") {}

#if defined(WIN_OS)
VirtualProgressBarWidget::VirtualProgressBarWidget(IUIAutomationElement* element)
    : NumericValueWidget(element), orientation_(Orientation::VERTICAL) {}
#endif