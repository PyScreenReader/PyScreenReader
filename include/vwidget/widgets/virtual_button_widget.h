#pragma once

#include <string>
#include "../virtual_widget.h"

class VirtualButtonWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
    VirtualButtonWidget() = default;
};