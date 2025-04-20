#include "include/vwidget/widgets/virtual_text_field_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualTextFieldWidget::getWidgetName() {
    return "VirtualTextFieldWidget";
}

bool VirtualTextFieldWidget::isClickable() {
    return true;
}

void bindTextFieldWidget(py::module_ &m) {
    py::class_<VirtualTextFieldWidget, VirtualWidget, std::shared_ptr<VirtualTextFieldWidget>>(m, "VirtualTextFieldWidget")
            .def("getWidgetName", &VirtualTextFieldWidget::getWidgetName)
            .def("isClickable", &VirtualTextFieldWidget::isClickable);
}

REGISTER_BINDING("VirtualTextFieldWidget", bindTextFieldWidget, "VirtualWidget")
