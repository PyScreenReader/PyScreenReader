#pragma once

#include <string>
#include "../virtual_widget.h"

class VirtualButtonWidget : public VirtualWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
};