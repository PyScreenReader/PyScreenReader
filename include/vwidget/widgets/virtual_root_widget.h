#pragma once

#include "include/vwidget/virtual_widget.h"

class VirtualRootWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
};