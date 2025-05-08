#pragma once

#include <string>
#include "../virtual_widget.h"

class VirtualMenuItemWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
};