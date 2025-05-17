#include "include/vwidget/widgets/virtual_window_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>


namespace py = pybind11;

std::string VirtualWindowWidget::GetWidgetName() {
    return "VirtualWindowWidget";
}

bool VirtualWindowWidget::IsClickable() {
    return true;
}

void BindVirtualWindowWidget(py::module_ &module) {
    py::class_<VirtualWindowWidget, VirtualWidget, std::shared_ptr<VirtualWindowWidget>>(module, "VirtualWindowWidget")
            .def(py::init())
            .def("getWidgetName", &VirtualWindowWidget::GetWidgetName)
            .def("isClickable", &VirtualWindowWidget::IsClickable);
}

REGISTER_BINDING("VirtualWindowWidget", BindVirtualWindowWidget, "VirtualWidget")