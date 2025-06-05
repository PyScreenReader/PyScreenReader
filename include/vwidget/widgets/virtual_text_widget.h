#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualTextWidget : public VirtualWidget {
 public:
  VirtualTextWidget();
  ~VirtualTextWidget() override = default;

  /**
   * Get cursor selected text in static text widget
   *
   * @return selected text
   */
  std::string& GetSelectedText() const { return selected_text_; }

  /**
   * Set cursor selected text
   *
   * @param selected_text selected text string
   */
  void SetSelectedText(const std::string& selected_text) { selected_text_ = selected_text; }

 private:
  std::string selected_text_;
};