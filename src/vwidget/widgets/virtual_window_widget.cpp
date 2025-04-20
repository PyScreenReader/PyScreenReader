#include "vwidget/widgets/virtual_window_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>


namespace py = pybind11;

std::string VirtualWindowWidget::getWidgetName() {
    return "VirtualWindowWidget";
}

bool VirtualWindowWidget::isClickable() {
    return true;
}

void bindVirtualWindowWidget(py::module_ &m) {
    py::class_<VirtualWindowWidget, VirtualContainerWidget, std::shared_ptr<VirtualWindowWidget>>(m, "VirtualWindowWidget")
            .def(py::init())
            .def("getWidgetName", &VirtualWindowWidget::getWidgetName)
            .def("isClickable", &VirtualWindowWidget::isClickable);
}

REGISTER_BINDING("VirtualWindowWidget", bindVirtualWindowWidget, "VirtualContainerWidget")