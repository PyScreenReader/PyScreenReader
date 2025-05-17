#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"


class VirtualTextWidget : public VirtualWidget {
private:
    bool is_clickable_;
public:
    VirtualTextWidget();
    std::string GetWidgetName() override;
    bool IsClickable() override;
    void SetClickable(bool newClickableValue);
};