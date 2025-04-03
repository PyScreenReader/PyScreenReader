#pragma once

#include <vector>
#include "virtual_widget.h"

class VirtualContainerWidget : public VirtualWidget {
private:
    std::vector<std::shared_ptr<VirtualWidget>> children_;

public:
    void addChild(const std::shared_ptr<VirtualWidget>& child) override;
    std::string getRepr() override;
    virtual ~VirtualContainerWidget() = default;
    const std::vector<std::shared_ptr<VirtualWidget>>& getChildren();
};