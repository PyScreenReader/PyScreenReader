#include "include/vwidget/widgets/virtual_progress_bar_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualProgressBarWidget::VirtualProgressBarWidget()
    : NumericValueWidget("VirtualProgressBarWidget") {}

void BindProgressBarWidget(pybind11::module_& module) {
  pybind11::class_<VirtualProgressBarWidget, NumericValueWidget,
                   std::shared_ptr<VirtualProgressBarWidget>>(module, "VirtualProgressBarWidget")
      .def(pybind11::init())
      .def("get_orientation", &VirtualProgressBarWidget::GetOrientation);
}

REGISTER_BINDING("VirtualProgressBarWidget", BindProgressBarWidget, "NumericValueWidget")
