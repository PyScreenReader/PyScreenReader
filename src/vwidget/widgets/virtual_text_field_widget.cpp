#include "include/vwidget/widgets/virtual_text_field_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string VirtualTextFieldWidget::GetWidgetName() {
  return "VirtualTextFieldWidget";
}

bool VirtualTextFieldWidget::IsClickable() { return true; }

void BindTextFieldWidget(py::module_ &module) {
  py::class_<VirtualTextFieldWidget, VirtualWidget,
             std::shared_ptr<VirtualTextFieldWidget>>(module,
                                                      "VirtualTextFieldWidget")
      .def("getWidgetName", &VirtualTextFieldWidget::GetWidgetName)
      .def("isClickable", &VirtualTextFieldWidget::IsClickable);
}

REGISTER_BINDING("VirtualTextFieldWidget", BindTextFieldWidget, "VirtualWidget")
