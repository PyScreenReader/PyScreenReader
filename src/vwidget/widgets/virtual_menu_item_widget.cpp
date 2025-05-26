#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualMenuItemWidget::GetWidgetName() {
  return "VirtualMenuItemWidget";
}

bool VirtualMenuItemWidget::IsClickable() { return true; }

void BindMenuItemWidget(py::module_ &module) {
  py::class_<VirtualMenuItemWidget, VirtualWidget,
             std::shared_ptr<VirtualMenuItemWidget>>(module,
                                                     "VirtualMenuItemWidget")
      .def("getWidgetName", &VirtualMenuItemWidget::GetWidgetName)
      .def("isClickable", &VirtualMenuItemWidget::IsClickable);
}

REGISTER_BINDING("VirtualMenuItemWidget", BindMenuItemWidget, "VirtualWidget")
