#include "include/vwidget/virtual_widget.h"
#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;


std::string VirtualWidget::getTitleText() const {
    return titleText_;
}

std::string VirtualWidget::getHelpText() const {
    return helpText_;
}

int VirtualWidget::getX() const {
    return x_;
}

int VirtualWidget::getY() const {
    return y_;
}

int VirtualWidget::getWidth() const {
    return width_;
}

int VirtualWidget::getHeight() const {
    return height_;
}

bool VirtualWidget::isVisible() const {
    return visible_;
}

std::shared_ptr<VirtualWidget> VirtualWidget::getParent() const {
    return parent_.lock();
}

void VirtualWidget::setTitleText(const std::string& titleText) {
    this->titleText_ = titleText;
}

void VirtualWidget::setHelpText(const std::string& helpText) {
    this->helpText_ = helpText;
}

void VirtualWidget::setX(int x) {
    this->x_ = x;
}

void VirtualWidget::setY(int y) {
    this->y_ = y;
}

void VirtualWidget::setWidth(int width) {
    this->width_ = width;
}

void VirtualWidget::setHeight(int height) {
    this->height_ = height;
}

void VirtualWidget::setParent(const std::shared_ptr<VirtualWidget> &parent) {
    this->parent_ = parent;
}

void VirtualWidget::setVisible(bool visible) {
    this->visible_ = visible;
}

std::string VirtualWidget::getRepr() {
    return getWidgetName() + "{title=" + getTitleText() +
           ", helpText=" + getHelpText() +
           ", isVisible=" + (isVisible() ? "true" : "false") +
           ", x=" + std::to_string(getX()) +
           ", y=" + std::to_string(getY()) +
           ", width=" + std::to_string(getWidth()) +
           ", height=" + std::to_string(getHeight()) + "}";
}

void bindVirtualWidget(py::module &m) {
    py::class_<VirtualWidget, std::shared_ptr<VirtualWidget>>(m, "VirtualWidget")
            .def("getTitleText", &VirtualWidget::getTitleText)
            .def("getHelpText", &VirtualWidget::getHelpText)
            .def("getX", &VirtualWidget::getX)
            .def("getY", &VirtualWidget::getY)
            .def("getWidth", &VirtualWidget::getWidth)
            .def("getHeight", &VirtualWidget::getHeight)
            .def("isVisible", &VirtualWidget::isVisible)
            .def("getParent", &VirtualWidget::getParent)
            .def("setTitleText", &VirtualWidget::setTitleText)
            .def("setHelpText", &VirtualWidget::setHelpText)
            .def("setX", &VirtualWidget::setX)
            .def("setY", &VirtualWidget::setY)
            .def("setWidth", &VirtualWidget::setWidth)
            .def("setHeight", &VirtualWidget::setHeight)
            .def("setParent", &VirtualWidget::setParent)
            .def("setVisible", &VirtualWidget::setVisible)
            .def("__repr__", &VirtualWidget::getRepr)
            .def("getWidgetName", &VirtualWidget::getWidgetName)
            .def("isClickable", &VirtualWidget::isVisible);
}

REGISTER_BINDING("VirtualWidget", bindVirtualWidget)
