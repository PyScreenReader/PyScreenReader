#pragma once

#include <atspi/atspi.h>
#include <memory>
#include "include/vwidget/virtual_widget.h"

namespace screen_reader {
class ScreenReaderImpl {
 public:
  ScreenReaderImpl();
  ~ScreenReaderImpl();

  std::shared_ptr<VirtualWidget> FromPID(const pid_t pid) const;

 private:
  AtspiAccessible* FindAtspiAccessibleByPID(AtspiAccessible* node, pid_t pid) const;
};
}  // namespace screen_reader
