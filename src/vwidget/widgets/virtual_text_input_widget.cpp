#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualTextInputWidget::VirtualTextInputWidget() : VirtualWidget("VirtualTextInputWidget") {}

void BindTextInputWidget(pybind11::module_& module) {
  pybind11::class_<VirtualTextInputWidget, VirtualWidget, std::shared_ptr<VirtualTextInputWidget>>(
      module, "VirtualTextInputWidget");
}

REGISTER_BINDING("VirtualTextInputWidget", BindTextInputWidget, "VirtualWidget")

