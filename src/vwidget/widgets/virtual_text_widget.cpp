#include "include/vwidget/widgets/virtual_text_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualTextWidget::getWidgetName() {
    return "VirtualTextWidget";
}

bool VirtualTextWidget::isClickable() {
    return false;
}

void bindVirtualTextWidget(pybind11::module_ &m) {
    py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(m, "VirtualTextWidget")
            .def("getWidgetName", &VirtualTextWidget::getWidgetName)
            .def("isClickable", &VirtualTextWidget::isClickable);
}

REGISTER_BINDING("VirtualTextWidget", bindVirtualTextWidget, "VirtualWidget")
