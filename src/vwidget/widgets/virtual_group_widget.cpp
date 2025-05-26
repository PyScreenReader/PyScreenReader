#include "include/vwidget/widgets/virtual_group_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualGroupWidget::GetWidgetName() { return "VirtualGroupWidget"; }

bool VirtualGroupWidget::IsClickable() { return true; }

void BindVirtualGroupWidget(py::module_ &module) {
  py::class_<VirtualGroupWidget, VirtualContainerWidget,
             std::shared_ptr<VirtualGroupWidget>>(module, "VirtualGroupWidget")
      .def(py::init())
      .def("getWidgetName", &VirtualGroupWidget::GetWidgetName)
      .def("isClickable", &VirtualGroupWidget::IsClickable);
}

REGISTER_BINDING("VirtualGroupWidget", BindVirtualGroupWidget,
                 "VirtualContainerWidget")