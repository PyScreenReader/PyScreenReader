#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

VirtualMenuItemWidget::VirtualMenuItemWidget() : VirtualWidget("VirtualMenuItemWidget") {}

void BindMenuItemWidget(pybind11::module_& module) {
  pybind11::class_<VirtualMenuItemWidget, VirtualWidget, std::shared_ptr<VirtualMenuItemWidget>>(
      module, "VirtualMenuItemWidget");
}

REGISTER_BINDING("VirtualMenuItemWidget", BindMenuItemWidget, "VirtualWidget")
