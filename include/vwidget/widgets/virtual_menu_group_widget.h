#pragma once

#include "../virtual_container_widget.h"
#include <string>

class VirtualMenuGroupWidget : public VirtualContainerWidget {
public:
  std::string GetWidgetName() override;
  bool IsClickable() override;
  VirtualMenuGroupWidget() = default;
};
