#pragma once

#include "../virtual_widget.h"
#include <string>

class VirtualButtonWidget : public VirtualWidget {
public:
  std::string GetWidgetName() override;
  bool IsClickable() override;
  VirtualButtonWidget() = default;
};