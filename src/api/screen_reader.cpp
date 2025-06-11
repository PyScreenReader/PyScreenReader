#include <stdexcept>

#include "include/api/screen_reader.h"

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByPID(const std::string &pid) const {
  return screen_reader_impl_.GetVirtualWidgetTreeByPID(pid);
}

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByTitle(const std::string &title) const {
  throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByClassName(
    const std::string &class_name) const {
  throw std::logic_error("Not yet implemented");
}
