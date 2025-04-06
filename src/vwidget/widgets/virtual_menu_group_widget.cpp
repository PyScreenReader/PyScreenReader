#include "vwidget/widgets/virtual_menu_group_widget.h"
#include "bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualMenuGroupWidget::getWidgetName() {
    return "VirtualMenuGroupWidget";
}

bool VirtualMenuGroupWidget::isClickable() {
    return false;
}

void bindMenuGroupWidget(pybind11::module_ &m) {
    py::class_<VirtualMenuGroupWidget, VirtualContainerWidget, std::shared_ptr<VirtualMenuGroupWidget>>(m, "VirtualMenuGroupWidget")
            .def("getWidgetName", &VirtualMenuGroupWidget::getWidgetName)
            .def("isClickable", &VirtualMenuGroupWidget::isClickable);
}

REGISTER_BINDING("VirtualMenuGroupWidget", bindMenuGroupWidget, "VirtualContainerWidget")
