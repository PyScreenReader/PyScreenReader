#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualUnknownWidget : public VirtualWidget {
 public:
  /**
   * Initialize a VirtualUnknownWidget.
   *
   * A VirtualUnknownWidget is a specific virtual widget that PyScreenReader uses
   * to represent that it cannot find a proper candidate to map from the system
   * native control / widget to virtual widgets. This is often used to be a fallback to indicate
   * there is no corresponding model in virtual widget system to shadow the native widget.
   */
  VirtualUnknownWidget();
  ~VirtualUnknownWidget() = default;
};