#include "include/vwidget/virtual_container_widget.h"

#include <stdexcept>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "src/bindings_registry.h"

namespace py = pybind11;

void VirtualContainerWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
    if (child.get() == this) {
        throw std::invalid_argument("One widget itself cannot be its own child.");
    }
    children_.push_back(child);
}

std::vector<std::shared_ptr<VirtualWidget>> &VirtualContainerWidget::GetChildren() {
    return children_;
}

void BindVirtualContainerWidget(py::module &module) {
    py::class_<VirtualContainerWidget, VirtualWidget, std::shared_ptr<VirtualContainerWidget>>(module, "VirtualContainerWidget")
            .def("addChild", &VirtualContainerWidget::AddChild, py::arg("child"))
            .def("getChildren", &VirtualContainerWidget::GetChildren);
}

REGISTER_BINDING("VirtualContainerWidget", BindVirtualContainerWidget, "VirtualWidget")
