#include "include/vwidget/widgets/virtual_menu_widget.h"
#include "src/bindings_registry.h"

#include <pybind11/pybind11.h>

VirtualMenuWidget::VirtualMenuWidget() : VirtualWidget("VirtualMenuWidget") {}

void BindMenuWidget(pybind11::module_& module) {
  pybind11::class_<VirtualMenuWidget, VirtualWidget, std::shared_ptr<VirtualMenuWidget>>(
      module, "VirtualMenuWidget")
      .def(pybind11::init());
}

REGISTER_BINDING("VirtualMenuWidget", BindMenuWidget, "VirtualWidget")
