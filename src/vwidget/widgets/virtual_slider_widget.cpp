#include "include/vwidget/widgets/virtual_slider_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualSliderWidget::VirtualSliderWidget() : NumericValueWidget("VirtualSliderWidget") {}

void BindSliderWidget(pybind11::module_& module) {
  pybind11::class_<VirtualSliderWidget, NumericValueWidget, std::shared_ptr<VirtualSliderWidget>>(
      module, "VirtualSliderWidget")
      .def(pybind11::init())
      .def("get_orientation", &VirtualSliderWidget::GetOrientation);
}

REGISTER_BINDING("VirtualSliderWidget", BindSliderWidget, "NumericValueWidget")
