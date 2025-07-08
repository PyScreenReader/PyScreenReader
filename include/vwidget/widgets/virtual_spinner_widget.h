#pragma once

#include "include/vwidget/orientation.h"
#include "include/vwidget/numeric_value_widget.h"

class VirtualSpinnerWidget : public NumericValueWidget {
 public:
  VirtualSpinnerWidget();
  ~VirtualSpinnerWidget() override = default;
#if defined(WIN_OS)
  explicit VirtualSpinnerWidget(IUIAutomationElement* element);
#endif
};