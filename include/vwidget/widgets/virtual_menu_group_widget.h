#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualMenuGroupWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
    VirtualMenuGroupWidget() = default;
};
