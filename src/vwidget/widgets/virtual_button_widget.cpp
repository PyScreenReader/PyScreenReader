#include "include/vwidget/widgets/virtual_button_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"


namespace py = pybind11;

std::string VirtualButtonWidget::GetWidgetName() {
    return "VirtualButtonWidget";
}

bool VirtualButtonWidget::IsClickable() {
    return true;
}

void BindVirtualButtonWidget(py::module_ &module) {
    py::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(module, "VirtualButtonWidget")
        .def(py::init())
        .def("getWidgetName", &VirtualButtonWidget::GetWidgetName)
        .def("isClickable", &VirtualButtonWidget::IsClickable);
}

REGISTER_BINDING("VirtualButtonWidget", BindVirtualButtonWidget, "VirtualWidget")
