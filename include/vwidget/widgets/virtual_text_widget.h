#pragma once

#include <string>
#include "../virtual_widget.h"


class VirtualTextWidget : public VirtualWidget {
private:
    bool isClickable_;
public:
    VirtualTextWidget();
    std::string getWidgetName() override;
    bool isClickable() override;
    void setClickable(bool newClickableValue);
};