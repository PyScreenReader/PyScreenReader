#include "include/vwidget/numeric_value_widget.h"
#include <pybind11/pybind11.h>
#include "include/vwidget/virtual_widget.h"
#include "src/bindings_registry.h"

NumericValueWidget::NumericValueWidget(const std::string& widget_name) : VirtualWidget(widget_name) {}

void BindNumericValueWidget(pybind11::module_& module) {
  pybind11::class_<NumericValueWidget, VirtualWidget>(
      module, "NumericValueWidget")
      .def("get_value", &NumericValueWidget::GetValue)
      .def("get_min_value", &NumericValueWidget::GetMinValue)
      .def("get_max_value", &NumericValueWidget::GetMaxValue);
}

REGISTER_BINDING("NumericValueWidget", BindNumericValueWidget, "VirtualWidget")
