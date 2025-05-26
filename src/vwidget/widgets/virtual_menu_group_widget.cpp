#include "include/vwidget/widgets/virtual_menu_group_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualMenuGroupWidget::GetWidgetName() {
  return "VirtualMenuGroupWidget";
}

bool VirtualMenuGroupWidget::IsClickable() { return false; }

void BindMenuGroupWidget(py::module_ &module) {
  py::class_<VirtualMenuGroupWidget, VirtualContainerWidget,
             std::shared_ptr<VirtualMenuGroupWidget>>(module,
                                                      "VirtualMenuGroupWidget")
      .def(py::init())
      .def("getWidgetName", &VirtualMenuGroupWidget::GetWidgetName)
      .def("isClickable", &VirtualMenuGroupWidget::IsClickable);
}

REGISTER_BINDING("VirtualMenuGroupWidget", BindMenuGroupWidget,
                 "VirtualContainerWidget")
