#include "include/vwidget/virtual_widget.h"
#include <pybind11/pybind11.h>

#include <utility>
#include "src/bindings_registry.h"

void VirtualWidget::AddChild(const std::shared_ptr<VirtualWidget>& child) {
  children_.emplace_back(child);
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetChild(int index) {
  return children_.at(index);
}

VirtualWidget::VirtualWidget(std::string widget_name) : widget_name_(std::move(widget_name)) {}

void BindVirtualWidget(const py::module& module) {
  py::class_<VirtualWidget>(module, "VirtualWidget")
      .def("get_title_text", &VirtualWidget::GetTitleText)
      .def("get_help_text", &VirtualWidget::GetHelpText)
      .def("get_native_name", &VirtualWidget::GetNativeName)
      .def("get_x", &VirtualWidget::GetX)
      .def("get_y", &VirtualWidget::GetY)
      .def("get_width", &VirtualWidget::GetWidth)
      .def("get_height", &VirtualWidget::GetHeight)
      .def("is_visible", &VirtualWidget::IsVisible)
      .def("is_focused", &VirtualWidget::IsFocused)
      .def("get_parent", &VirtualWidget::GetParent)
      .def("get_child", &VirtualWidget::GetChild)
      .def("__repr__", &VirtualWidget::GetRepr)
      .def("get_widget_name", &VirtualWidget::GetWidgetName);
}

REGISTER_BINDING("VirtualWidget", BindVirtualWidget)
