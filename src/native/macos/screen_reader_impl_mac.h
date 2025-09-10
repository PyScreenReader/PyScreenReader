#pragma once
#include <memory>
#include <string>

#include "include/vwidget/virtual_widget.h"

namespace screen_reader {
class ScreenReaderImpl {
 public:
  ScreenReaderImpl() = default;
  ~ScreenReaderImpl() = default;

  static std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByPID(const pid_t pid);
};
}  // namespace screen_reader
