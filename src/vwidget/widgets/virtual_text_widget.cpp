#include "vwidget/widgets/virtual_text_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

VirtualTextWidget::VirtualTextWidget(): isClickable_(false) {}

std::string VirtualTextWidget::getWidgetName() {
    return "VirtualTextWidget";
}

bool VirtualTextWidget::isClickable() {
    return this->isClickable_;
}

void VirtualTextWidget::setClickable(bool newClickableValue) {
    this->isClickable_ = newClickableValue;
}

void bindVirtualTextWidget(py::module_ &m) {
    py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(m, "VirtualTextWidget")
            .def("getWidgetName", &VirtualTextWidget::getWidgetName)
            .def("isClickable", &VirtualTextWidget::isClickable);
}

REGISTER_BINDING("VirtualTextWidget", bindVirtualTextWidget, "VirtualWidget")
