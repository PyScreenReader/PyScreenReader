#include "include/vwidget/widgets/virtual_text_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

VirtualTextWidget::VirtualTextWidget() : VirtualWidget("VirtualTextWidget") {}

void BindVirtualTextWidget(pybind11::module_ &module) {
  pybind11::class_<VirtualTextWidget, VirtualWidget,
             std::shared_ptr<VirtualTextWidget>>(module, "VirtualTextWidget")
    .def(pybind11::init())
    .def("get_selected_text", &VirtualTextWidget::GetSelectedText);
}

REGISTER_BINDING("VirtualTextWidget", BindVirtualTextWidget, "VirtualWidget")
