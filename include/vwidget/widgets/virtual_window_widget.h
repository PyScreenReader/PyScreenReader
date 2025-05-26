#pragma once

#include "include/vwidget/virtual_container_widget.h"
#include <string>

class VirtualWindowWidget : public VirtualContainerWidget {
public:
  std::string GetWidgetName() override;
  bool IsClickable() override;
  VirtualWindowWidget() = default;
};
