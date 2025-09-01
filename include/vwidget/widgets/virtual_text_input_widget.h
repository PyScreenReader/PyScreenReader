#pragma once

#include <string>

#include "include/vwidget/virtual_widget.h"
#include "virtual_text_widget.h"

class VirtualTextInputWidget : public VirtualTextWidget {
 public:
  VirtualTextInputWidget();
  ~VirtualTextInputWidget() override = default;

  /**
   * Get current cursor location in the text input, represented by an index number
   * starting 0.
   *
   * For example, in "A|BCDEFG", this function will return 1.
   *
   * @return current cursor index in the text input
   */
  int GetInsertionPoint() const { return insertion_point_; }
  /**
   * Set current cursor location index in the text input.
   *
   * @param insertion_point index starting 0
   * @see GetInsertionPoint()
   */
  void SetInsertionPoint(int insertion_point) { insertion_point_ = insertion_point; }

  /**
   * Get if the current text input is the text area invariant.
   *
   * @return True if the text input is a text area, otherwise False.
   */
  bool IsTextArea() const { return is_text_area_; }
  /**
   * Set if the current text input is the text area invariant.
   *
   * @param is_text_area True if the text input is a text field, otherwise False.
   */
  void SetIsTextArea(bool is_text_area) { is_text_area_ = is_text_area; }

 private:
  int insertion_point_ = -1;
  bool is_text_area_ = false;
};