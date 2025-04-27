#pragma once

#include <string>
#include "../virtual_container_widget.h"

class VirtualWindowWidget : public VirtualContainerWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
    VirtualWindowWidget() = default;
};
