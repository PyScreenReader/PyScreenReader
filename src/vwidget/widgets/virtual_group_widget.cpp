#include "vwidget/widgets/virtual_group_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>


namespace py = pybind11;

std::string VirtualGroupWidget::getWidgetName() {
    return "VirtualGroupWidget";
}

bool VirtualGroupWidget::isClickable() {
    return true;
}

void bindVirtualGroupWidget(py::module_ &m) {
    py::class_<VirtualGroupWidget, VirtualContainerWidget, std::shared_ptr<VirtualGroupWidget>>(m, "VirtualGroupWidget")
            .def(py::init())
            .def("getWidgetName", &VirtualGroupWidget::getWidgetName)
            .def("isClickable", &VirtualGroupWidget::isClickable);
}

REGISTER_BINDING("VirtualGroupWidget", bindVirtualGroupWidget, "VirtualContainerWidget")