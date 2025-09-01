#include "include/vwidget/numeric_value_widget.h"
#include "include/vwidget/virtual_widget.h"

NumericValueWidget::NumericValueWidget(std::string&& widget_name)
    : VirtualWidget(std::move(widget_name)) {}