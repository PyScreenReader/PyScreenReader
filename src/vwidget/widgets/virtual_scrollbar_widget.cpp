#include "include/vwidget/widgets/virtual_scrollbar_widget.h"
#include "include/vwidget/orientation.h"

VirtualScrollbarWidget::VirtualScrollbarWidget() : NumericValueWidget("VirtualScrollbarWidget") {
  orientation_ = Orientation::VERTICAL;
}

#if defined(WIN_OS)
VirtualScrollbarWidget::VirtualScrollbarWidget(IUIAutomationElement* element)
    : NumericValueWidget(element), orientation_(Orientation::VERTICAL) {}
#endif