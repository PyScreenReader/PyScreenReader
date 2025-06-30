#pragma once

#include <string>
#include "include/vwidget/virtual_widget.h"

class VirtualGroupWidget : public VirtualWidget {
 public:
  /**
   * Initialize a VirtualGroupWidget.
   *
   * A VirtualGroupWidget represents any container-like native widget
   * that groups other widgets together, such as rows, columns, lists,
   * or generic groups in the accessibility tree.
   *
   * This widget can have child widgets but does not typically have
   * direct user interactions itself.
     */
  VirtualGroupWidget();
  ~VirtualGroupWidget() override = default;
};