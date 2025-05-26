#pragma once

#include "virtual_widget.h"
#include <memory>
#include <vector>

class VirtualContainerWidget : public VirtualWidget {
public:
  ~VirtualContainerWidget() override = default;
  void AddChild(const std::shared_ptr<VirtualWidget> &child) override;
  std::vector<std::shared_ptr<VirtualWidget>> &GetChildren();

private:
  std::vector<std::shared_ptr<VirtualWidget>> children_;
};
