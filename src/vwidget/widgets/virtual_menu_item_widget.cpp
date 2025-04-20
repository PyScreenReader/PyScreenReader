#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualMenuItemWidget::getWidgetName() {
    return "VirtualMenuItemWidget";
}

bool VirtualMenuItemWidget::isClickable() {
    return true;
}

void bindMenuItemWidget(py::module_ &m) {
    py::class_<VirtualMenuItemWidget, VirtualWidget, std::shared_ptr<VirtualMenuItemWidget>>(m, "VirtualMenuItemWidget")
            .def("getWidgetName", &VirtualMenuItemWidget::getWidgetName)
            .def("isClickable", &VirtualMenuItemWidget::isClickable);
}

REGISTER_BINDING("VirtualMenuItemWidget", bindMenuItemWidget, "VirtualWidget")
