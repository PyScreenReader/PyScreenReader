#pragma once

#include <string>
#include "vwidget/virtual_container_widget.h"

class VirtualUnknownWidget : public VirtualContainerWidget {
private:
    bool isClickable_;
    std::string nativeName_;
public:
    VirtualUnknownWidget();
    std::string getWidgetName() override;
    bool isClickable() override;
    void setClickable(bool newClickableValue);
    const std::string& getNativeName() const;
    void setNativeName(const std::string& name);
};