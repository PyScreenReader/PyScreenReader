#include "include/vwidget/virtual_widget.h"
#include <pybind11/pybind11.h>
#include "src/bindings_registry.h"

namespace py = pybind11;

std::string VirtualWidget::GetRepr() {
  return GetWidgetName() + "{title=" + GetTitleText() + ", helpText=" + GetHelpText() +
         ", isVisible=" + (IsVisible() ? "true" : "false") + ", x=" + std::to_string(GetX()) +
         ", y=" + std::to_string(GetY()) + ", width=" + std::to_string(GetWidth()) +
         ", height=" + std::to_string(GetHeight()) + "}";
}

void BindVirtualWidget(const py::module& module) {
  py::class_<VirtualWidget, std::shared_ptr<VirtualWidget>>(module, "VirtualWidget")
      .def("getTitleText", &VirtualWidget::GetTitleText)
      .def("getHelpText", &VirtualWidget::GetHelpText)
      .def("getX", &VirtualWidget::GetX)
      .def("getY", &VirtualWidget::GetY)
      .def("getWidth", &VirtualWidget::GetWidth)
      .def("getHeight", &VirtualWidget::GetHeight)
      .def("isVisible", &VirtualWidget::IsVisible)
      .def("getParent", &VirtualWidget::GetParent)
      .def("setTitleText", &VirtualWidget::SetTitleText)
      .def("setHelpText", &VirtualWidget::SetHelpText)
      .def("setX", &VirtualWidget::SetX)
      .def("setY", &VirtualWidget::SetY)
      .def("setWidth", &VirtualWidget::SetWidth)
      .def("setHeight", &VirtualWidget::SetHeight)
      .def("setParent", &VirtualWidget::SetParent)
      .def("setVisible", &VirtualWidget::SetVisible)
      .def("__repr__", &VirtualWidget::GetRepr)
      .def("getWidgetName", &VirtualWidget::GetWidgetName)
      .def("isClickable", &VirtualWidget::IsVisible);
}

REGISTER_BINDING("VirtualWidget", BindVirtualWidget)
