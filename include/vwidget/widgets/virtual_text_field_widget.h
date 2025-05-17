#pragma once

#include "include/vwidget/virtual_widget.h"
#include <string>

class VirtualTextFieldWidget : public VirtualWidget {
public:
    std::string GetWidgetName() override;
    bool IsClickable() override;
};