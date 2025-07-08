#include "include/vwidget/widgets/virtual_slider_widget.h"

VirtualSliderWidget::VirtualSliderWidget() : NumericValueWidget("VirtualSliderWidget") {}

#if defined(WIN_OS)
VirtualSliderWidget::VirtualSliderWidget(IUIAutomationElement* element)
    : NumericValueWidget(element), orientation_(Orientation::VERTICAL) {}
#endif