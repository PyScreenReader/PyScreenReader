#pragma once

#include <string>
#include "../virtual_container_widget.h"

class VirtualMenuGroupWidget : public VirtualContainerWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
    VirtualMenuGroupWidget() = default;
};
