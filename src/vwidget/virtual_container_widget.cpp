#include "vwidget/virtual_container_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void VirtualContainerWidget::addChild(const std::shared_ptr<VirtualWidget>& child) {
    if (child.get() == this)
        throw std::invalid_argument("One widget itself cannot be its own child.");
    children_.push_back(child);
}

std::vector<std::shared_ptr<VirtualWidget>> &VirtualContainerWidget::getChildren() {
    return children_;
}

void bindVirtualContainerWidget(pybind11::module &m) {
    py::class_<VirtualContainerWidget, VirtualWidget, std::shared_ptr<VirtualContainerWidget>>(m, "VirtualContainerWidget")
            .def("addChild", &VirtualContainerWidget::addChild, py::arg("child"))
            .def("getChildren", &VirtualContainerWidget::addChild);
}

REGISTER_BINDING("VirtualContainerWidget", bindVirtualContainerWidget, "VirtualWidget")
