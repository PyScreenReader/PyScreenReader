#include <stdexcept>

#include "include/api/screen_reader.h"

std::shared_ptr<VirtualWidget> ScreenReader::GetVirtualWidgetTreeByPID(
    const pid_t pid) const {
  return screen_reader_impl_.GetVirtualWidgetTreeByPID(pid);
}
