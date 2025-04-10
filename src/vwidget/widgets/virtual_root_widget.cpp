#include "vwidget/widgets/virtual_root_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualRootWidget::getWidgetName() {
    return "VirtualRootWidget";
}

bool VirtualRootWidget::isClickable() {
    return false;
}

void bindRootWidget(pybind11::module_ &m) {
    py::class_<VirtualRootWidget, VirtualContainerWidget, std::shared_ptr<VirtualRootWidget>>(m, "VirtualRootWidget")
        .def("getWidgetName", &VirtualRootWidget::getWidgetName)
        .def("isClickable", &VirtualRootWidget::isClickable);
}

REGISTER_BINDING("VirtualRootWidget", bindRootWidget, "VirtualContainerWidget")
