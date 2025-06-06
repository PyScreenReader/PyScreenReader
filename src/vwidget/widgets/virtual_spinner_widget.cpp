#include "include/vwidget/widgets/virtual_spinner_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualSpinnerWidget::VirtualSpinnerWidget() : NumericValueWidget("VirtualSpinnerWidget") {}

void BindSpinnerWidget(pybind11::module_& module) {
  pybind11::class_<VirtualSpinnerWidget, NumericValueWidget, std::shared_ptr<VirtualSpinnerWidget>>(
      module, "VirtualSpinnerWidget")
      .def(pybind11::init());
}

REGISTER_BINDING("VirtualSpinnerWidget", BindSpinnerWidget, "NumericValueWidget")
