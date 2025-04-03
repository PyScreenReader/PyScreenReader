#pragma once

#include "../virtual_widget.h"
#include <string>

class VirtualTextFieldWidget : public VirtualWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
};