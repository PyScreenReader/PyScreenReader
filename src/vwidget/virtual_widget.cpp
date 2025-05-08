#include "include/vwidget/virtual_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;


std::string VirtualWidget::GetTitleText() const {
    return title_text_;
}

std::string VirtualWidget::GetHelpText() const {
    return help_text_;
}

int VirtualWidget::GetX() const {
    return x_;
}

int VirtualWidget::GetY() const {
    return y_;
}

int VirtualWidget::GetWidth() const {
    return width_;
}

int VirtualWidget::GetHeight() const {
    return height_;
}

bool VirtualWidget::IsVisible() const {
    return visible_;
}

std::shared_ptr<VirtualWidget> VirtualWidget::GetParent() const {
    return parent_.lock();
}

void VirtualWidget::SetTitleText(const std::string& title_text) {
    this->title_text_ = title_text;
}

void VirtualWidget::SetHelpText(const std::string& help_text) {
    this->help_text_ = help_text;
}

void VirtualWidget::SetX(int x_coord) {
    this->x_ = x_coord;
}

void VirtualWidget::SetY(int y_coord) {
    this->y_ = y_coord;
}

void VirtualWidget::SetWidth(int width) {
    this->width_ = width;
}

void VirtualWidget::SetHeight(int height) {
    this->height_ = height;
}

void VirtualWidget::SetParent(const std::shared_ptr<VirtualWidget> &parent) {
    this->parent_ = parent;
}

void VirtualWidget::SetVisible(bool visible) {
    this->visible_ = visible;
}

std::string VirtualWidget::GetRepr() {
    return GetWidgetName() + "{title=" + GetTitleText() +
           ", helpText=" + GetHelpText() +
           ", isVisible=" + (IsVisible() ? "true" : "false") +
           ", x=" + std::to_string(GetX()) +
           ", y=" + std::to_string(GetY()) +
           ", width=" + std::to_string(GetWidth()) +
           ", height=" + std::to_string(GetHeight()) + "}";
}

void BindVirtualWidget(py::module &module) {
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
