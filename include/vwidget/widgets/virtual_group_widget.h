#pragma once

#include <string>
#include "../virtual_container_widget.h"

class VirtualGroupWidget : public VirtualContainerWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
    VirtualGroupWidget() = default;
};
