#pragma once

#include <string>
#include "../virtual_widget.h"


class VirtualTextWidget : public VirtualWidget {
public:
    std::string getWidgetName() override;
    bool isClickable() override;
};