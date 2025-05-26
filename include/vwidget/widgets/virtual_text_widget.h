#pragma once

#include "../virtual_widget.h"
#include <string>

class VirtualTextWidget : public VirtualWidget {
private:
  bool is_clickable_;

public:
  VirtualTextWidget();
  std::string GetWidgetName() override;
  bool IsClickable() override;
  void SetClickable(bool newClickableValue);
};