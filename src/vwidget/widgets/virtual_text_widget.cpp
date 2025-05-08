#include "include/vwidget/widgets/virtual_text_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

VirtualTextWidget::VirtualTextWidget(): is_clickable_(false) {}

std::string VirtualTextWidget::GetWidgetName() {
    return "VirtualTextWidget";
}

bool VirtualTextWidget::IsClickable() {
    return this->is_clickable_;
}

void VirtualTextWidget::SetClickable(bool new_clickable_value) {
    this->is_clickable_ = new_clickable_value;
}

void BindVirtualTextWidget(py::module_ &module) {
    py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(module, "VirtualTextWidget")
            .def("getWidgetName", &VirtualTextWidget::GetWidgetName)
            .def("isClickable", &VirtualTextWidget::IsClickable);
}

REGISTER_BINDING("VirtualTextWidget", BindVirtualTextWidget, "VirtualWidget")
