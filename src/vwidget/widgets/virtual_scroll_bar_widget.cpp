#include <pybind11/pybind11.h>
#include "include/vwidget/widgets/virtual_scroll_bar_widget.h"
#include "src/bindings_registry.h"

VirtualScrollbarWidget::VirtualScrollbarWidget() : VirtualWidget("VirtualScrollbarWidget") {}

void BindScrollbarWidget(pybind11::module_& module) {
  pybind11::class_<VirtualScrollbarWidget, NumericValueWidget,
                   std::shared_ptr<VirtualScrollbarWidget>>(module, "VirtualScrollbarWidget")
      .def(pybind11::init())
      .def("get_orientation", &VirtualScrollbarWidget::GetOrientation);
}

REGISTER_BINDING("VirtualScrollbarWidget", BindScrollbarWidget, "NumericValueWidget")
