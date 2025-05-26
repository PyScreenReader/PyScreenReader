#pragma once

#include "../virtual_widget.h"
#include <string>

class VirtualMenuItemWidget : public VirtualWidget {
public:
  std::string GetWidgetName() override;
  bool IsClickable() override;
};