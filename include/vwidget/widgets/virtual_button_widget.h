#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualButtonWidget : public VirtualWidget {
 public:
  VirtualButtonWidget();
  ~VirtualButtonWidget() override = default;
#if defined(WIN_OS)
  explicit VirtualButtonWidget(IUIAutomationElement* element);
#endif
};