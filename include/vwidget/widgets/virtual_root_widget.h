#pragma once

#include "../virtual_container_widget.h"

class VirtualRootWidget : public VirtualContainerWidget {
public:
  std::string GetWidgetName() override;
  bool IsClickable() override;
};