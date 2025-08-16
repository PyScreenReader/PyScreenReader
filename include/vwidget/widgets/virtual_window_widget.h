#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualWindowWidget : public VirtualWidget {
 public:
  VirtualWindowWidget();
  ~VirtualWindowWidget() override = default;

  /**
   * Get if the current window is a modal.
   *
   * Depending on the native system, A "modal" generally means a pop-up window that
   * appears on the top of its main content and blocks user interactions with the rest of
   * the UI until user completes specific actions or dismiss it.
   *
   * @return True if current window is a modal, otherwise False.
   */
  bool IsModal() const { return is_modal_; }

  /**
   * Set if current window is a modal.
   *
   * @param is_modal true if current window is a modal, otherwise false.
   */
  void SetIsModal(bool is_modal) { is_modal_ = is_modal; }

 private:
  bool is_modal_ = false;
};
