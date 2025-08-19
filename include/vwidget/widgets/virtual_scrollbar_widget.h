#pragma once

#include "include/vwidget/numeric_value_widget.h"
#include "include/vwidget/orientation.h"

class VirtualScrollbarWidget : public NumericValueWidget {
 public:
  VirtualScrollbarWidget();
  ~VirtualScrollbarWidget() override = default;

  /**
   * Get current orientation of the widget.
   *
   * @return orientation of the widget.
   */
  Orientation GetOrientation() const { return orientation_; }

  /**
   * Set current orientation of the widget.
   *
   * @param orientation orientation of the widget.
   */
  void SetOrientation(const Orientation& orientation) { orientation_ = orientation; }

 private:
  Orientation orientation_ = Orientation::VERTICAL;
};