#include "include/vwidget/widgets/virtual_button_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"


VirtualButtonWidget::VirtualButtonWidget() : VirtualWidget("VirtualButtonWidget") {};

void BindVirtualButtonWidget(pybind11::module_& module) {
  pybind11::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(
      module, "VirtualButtonWidget")
      .def(pybind11::init());
}

REGISTER_BINDING("VirtualButtonWidget", BindVirtualButtonWidget, "VirtualWidget")
