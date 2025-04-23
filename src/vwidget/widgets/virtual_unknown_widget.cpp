#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualUnknownWidget::getWidgetName() {
    return "VirtualUnknownWidget";
}

bool VirtualUnknownWidget::isClickable() {
    return this->isClickable_;
}

void VirtualUnknownWidget::setClickable(bool newClickableValue) {
    this->isClickable_ = newClickableValue;
}

VirtualUnknownWidget::VirtualUnknownWidget(): isClickable_(false) {}

const std::string &VirtualUnknownWidget::getNativeName() const {
    return this->nativeName_;
}

void VirtualUnknownWidget::setNativeName(const std::string &name) {
    this->nativeName_ = name;
}

void bindVirtualUnknownWidget(py::module_ &m) {
    py::class_<VirtualUnknownWidget, VirtualContainerWidget, std::shared_ptr<VirtualUnknownWidget>>(m, "VirtualUnknownWidget")
            .def(py::init())
            .def("getWidgetName", &VirtualUnknownWidget::getWidgetName)
            .def("isClickable", &VirtualUnknownWidget::isClickable)
            .def("setClickable", &VirtualUnknownWidget::setClickable)
            .def("getNativeName", &VirtualUnknownWidget::getNativeName)
            .def("setNativeName", &VirtualUnknownWidget::setNativeName);
}

REGISTER_BINDING("VirtualUnknownWidget", bindVirtualUnknownWidget, "VirtualContainerWidget")