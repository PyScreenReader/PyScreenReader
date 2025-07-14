#pragma once

#include "include/vwidget/orientation.h"
#include "include/vwidget/numeric_value_widget.h"

class VirtualSpinnerWidget : public NumericValueWidget {
 public:
  VirtualSpinnerWidget();
  ~VirtualSpinnerWidget() override = default;
};