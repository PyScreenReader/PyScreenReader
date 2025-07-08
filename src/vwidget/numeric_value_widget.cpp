#include "include/vwidget/numeric_value_widget.h"
#include "include/vwidget/virtual_widget.h"

NumericValueWidget::NumericValueWidget(const std::string& widget_name) : VirtualWidget(widget_name) {}

#if defined(WIN_OS)
NumericValueWidget::NumericValueWidget(IUIAutomationElement* element)
    : VirtualWidget(element), value_(0), min_value_(0), max_value_(0) {}
#endif