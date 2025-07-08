#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualGroupWidget : public VirtualWidget {
 public:
  /**
   * Initializes a VirtualGroupWidget.
   *
   * A VirtualGroupWidget represents a container-like native widget
   * that groups other widgets together in the accessibility tree.
   * Examples include rows, columns, lists, or generic grouping elements.
   *
   * This abstraction models the hierarchical structure of the widget tree.
   * A VirtualGroupWidget typically does not handle direct user interactions itself.
   * If the native widget has specific interactive behaviors or functionalities,
   * it should generally not be mapped to a VirtualGroupWidget.
   */
  VirtualGroupWidget();
  ~VirtualGroupWidget() override = default;
};