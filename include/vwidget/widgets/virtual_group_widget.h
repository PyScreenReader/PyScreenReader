#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualGroupWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
    VirtualGroupWidget() = default;
};
