#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualMenuWidget : public VirtualWidget {
 public:
  VirtualMenuWidget();
  ~VirtualMenuWidget() override = default;
#if defined(WIN_OS)
  explicit VirtualMenuWidget(IUIAutomationElement* element);
#endif
};