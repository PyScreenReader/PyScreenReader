#pragma once

#include <string>
#include "include/vwidget/virtual_container_widget.h"

class VirtualGroupWidget : public VirtualContainerWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
    VirtualGroupWidget() = default;
};
