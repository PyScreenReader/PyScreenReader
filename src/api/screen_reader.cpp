#include <stdexcept>

#include "include/api/screen_reader.h"

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByPID(const std::string &pid) const {
  return screen_reader_impl_.GetVirtualWidgetTreeByPID(pid);
}
