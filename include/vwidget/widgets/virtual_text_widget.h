#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualTextWidget : public VirtualWidget {
 public:
  VirtualTextWidget();
  explicit VirtualTextWidget(std::string widget_name);
  ~VirtualTextWidget() override = default;

  /**
   * Get cursor selected text in static text widget
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
     * Convert this object to a formatted printable string.
     *
     * @return formatted printable string
     */
  std::string ToString() const override;

 protected:
  std::string selected_text_;
};