#pragma once

#include "include/vwidget/virtual_widget.h"
#include <atspi/atspi.h>
#include <memory>

namespace screen_reader {
class ScreenReaderImpl {
public:
  ScreenReaderImpl();
  ~ScreenReaderImpl();

  std::shared_ptr<VirtualWidget>
  GetVirtualWidgetTreeByPID(const std::string &pid) const;

private:
  AtspiAccessible *FindAtspiAccessibleByPID(AtspiAccessible *node, pid_t pid) const;
};
} // namespace screen_reader

