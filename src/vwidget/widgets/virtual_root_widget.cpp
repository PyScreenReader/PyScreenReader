#include "include/vwidget/widgets/virtual_root_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualRootWidget::GetWidgetName() {
    return "VirtualRootWidget";
}

bool VirtualRootWidget::IsClickable() {
    return false;
}

void BindRootWidget(py::module_ &module) {
    py::class_<VirtualRootWidget, VirtualWidget, std::shared_ptr<VirtualRootWidget>>(module, "VirtualRootWidget")
        .def("getWidgetName", &VirtualRootWidget::GetWidgetName)
        .def("isClickable", &VirtualRootWidget::IsClickable);
}

REGISTER_BINDING("VirtualRootWidget", BindRootWidget, "VirtualWidget")
