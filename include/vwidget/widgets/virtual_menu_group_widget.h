#pragma once

#include <string>
#include "../virtual_container_widget.h"

class VirtualMenuGroupWidget : public VirtualContainerWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
    VirtualMenuGroupWidget() = default;
};
