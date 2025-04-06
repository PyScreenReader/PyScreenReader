#include "vwidget/widgets/virtual_button_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>


namespace py = pybind11;

VirtualButtonWidget::VirtualButtonWidget() = default;

std::string VirtualButtonWidget::getWidgetName() {
    return "VirtualButtonWidget";
}

bool VirtualButtonWidget::isClickable() {
    return true;
}

void bindVirtualButtonWidget(pybind11::module_ &m) {
    py::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(m, "VirtualButtonWidget")
        .def(py::init())
        .def("getWidgetName", &VirtualButtonWidget::getWidgetName)
        .def("isClickable", &VirtualButtonWidget::isClickable);
}

REGISTER_BINDING("VirtualButtonWidget", bindVirtualButtonWidget, "VirtualWidget")
