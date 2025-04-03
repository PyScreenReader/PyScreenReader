#include "vwidget/virtual_container_widget.h"

void VirtualContainerWidget::addChild(const std::shared_ptr<VirtualWidget>& child) {
    if (child.get() == this)
        throw std::invalid_argument("One widget itself cannot be its own child.");
    children_.push_back(child);
}

std::string VirtualContainerWidget::getRepr() {
    std::string repr = VirtualWidget::getRepr() +
                       "{title=" + getTitleText() +
                       ", help=" + getHelpText() +
                       ", x=" + std::to_string(getX()) +
                       ", y=" + std::to_string(getY()) +
                       ", width=" + std::to_string(getWidth()) +
                       ", height=" + std::to_string(getHeight()) +
                       ", children=[";

    for (size_t i = 0; i < children_.size(); ++i) {
        repr += children_[i]->getRepr();
        if (i < children_.size() - 1) {
            repr += ", ";
        }
    }

    repr += "]}";
    return repr;
}
