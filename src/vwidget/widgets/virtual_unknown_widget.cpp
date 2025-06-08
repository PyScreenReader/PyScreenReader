#include "src/bindings_registry.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"

#include <pybind11/pybind11.h>

VirtualUnknownWidget::VirtualUnknownWidget() : VirtualWidget("VirtualUnknownWidget") {}

void BindVirtualUnknownWidget(pybind11::module_& module) {
  py::class_<VirtualUnknownWidget, std::shared_ptr<VirtualUnknownWidget>>(
      module, "VirtualUnknownWidget")
      .def(pybind11::init());
}

REGISTER_BINDING("VirtualUnknownWidget", BindVirtualUnknownWidget, "VirtualWidget")