#include "include/vwidget/widgets/virtual_window_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualWindowWidget::VirtualWindowWidget() : VirtualWidget("VirtualWindowWidget") {}

void BindVirtualWindowWidget(pybind11::module_& module) {
  pybind11::class_<VirtualWindowWidget, VirtualWidget,
                   std::shared_ptr<VirtualWindowWidget>>(module, "VirtualWindowWidget")
      .def(pybind11::init());
}

REGISTER_BINDING("VirtualWindowWidget", BindVirtualWindowWidget, "VirtualWidget")
