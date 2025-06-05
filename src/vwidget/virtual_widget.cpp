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

void VirtualWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
  children_.emplace_back(child);
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetChild(int index) {
  return children_.get(index);
}

VirtualWidget::VirtualWidget(const std::string& widget_name) : widget_name_(widget_name) {}

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
      .def("__repr__", &VirtualWidget::GetRepr)
      .def("getWidgetName", &VirtualWidget::GetWidgetName)
      .def("isClickable", &VirtualWidget::IsVisible);
}

REGISTER_BINDING("VirtualWidget", BindVirtualWidget)
