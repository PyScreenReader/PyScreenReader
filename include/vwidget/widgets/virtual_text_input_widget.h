#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualTextInputWidget : public VirtualWidget {
 public:
  VirtualTextInputWidget();
  ~VirtualTextInputWidget() override = default;

  /**
   * Get cursor selected text in text input
   *
   * @return selected text
   */
  const std::string& GetSelectedText() const { return selected_text_; }
  /**
   * Set cursor selected text
   *
   * @param selected_text selected text string
   */
  void SetSelectedText(const std::string& selected_text) { selected_text_ = selected_text; }

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
  std::string selected_text_;
  int insertion_point_;
  bool is_text_area_;
};