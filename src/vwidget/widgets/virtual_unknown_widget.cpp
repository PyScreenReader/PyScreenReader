#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualUnknownWidget::GetWidgetName() {
    return "VirtualUnknownWidget";
}

bool VirtualUnknownWidget::IsClickable() {
    return this->is_clickable_;
}

void VirtualUnknownWidget::SetClickable(bool new_clickable_value) {
    this->is_clickable_ = new_clickable_value;
}

VirtualUnknownWidget::VirtualUnknownWidget(): is_clickable_(false) {}

const std::string &VirtualUnknownWidget::GetNativeName() const {
    return this->native_name_;
}

void VirtualUnknownWidget::SetNativeName(const std::string &name) {
    this->native_name_ = name;
}

void BindVirtualUnknownWidget(py::module_ &module) {
    py::class_<VirtualUnknownWidget, VirtualWidget, std::shared_ptr<VirtualUnknownWidget>>(module, "VirtualUnknownWidget")
            .def(py::init())
            .def("getWidgetName", &VirtualUnknownWidget::GetWidgetName)
            .def("isClickable", &VirtualUnknownWidget::IsClickable)
            .def("setClickable", &VirtualUnknownWidget::SetClickable)
            .def("getNativeName", &VirtualUnknownWidget::GetNativeName)
            .def("setNativeName", &VirtualUnknownWidget::SetNativeName);
}

REGISTER_BINDING("VirtualUnknownWidget", BindVirtualUnknownWidget, "VirtualWidget")