#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class NumericValueWidget : public VirtualWidget {
 public:
  /**
   * Get value contained in the widget
   *
   * @return value contained in the widget
   */
  int GetValue() const { return value_; }

  /**
   * Set value contained in the widget
   *
   * @param value number value
   */
  void SetValue(int value) { value_ = value; }

  /**
   * Get lower bound of the value
   *
   * @return min value of the range
   */
  int GetMinValue() const { return min_value_; }

  /**
   * Set lower bound of the value
   *
   * @param min_value min value of the range
   */
  void SetMinValue(int min_value) { min_value_ = min_value; }

  /**
   * Set upper bound of the value
   *
   * @return max value of the range
   */
  int GetMaxValue() const { return max_value_; }

  /**
   * Set upper bound of the value
   *
   * @param max_value max value of the range
   */
  void SetMaxValue(int max_value) { max_value_ = max_value; }

  ~NumericValueWidget() override = default;

 private:
  int value_ = -1;
  int min_value_ = -1;
  int max_value_ = -1;

 protected:
  explicit NumericValueWidget(std::string&& widget_name);
};