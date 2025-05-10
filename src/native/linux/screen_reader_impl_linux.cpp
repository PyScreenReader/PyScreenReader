#include "src/native/linux/screen_reader_impl_linux.h"
#include <memory>
#include <stdexcept>

namespace screen_reader {
std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
  throw std::logic_error("Not yet implemented");
  return nullptr;
}

std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
  throw std::logic_error("Not yet implemented");
  return nullptr;
}

std::shared_ptr<VirtualRootWidget>
ScreenReaderImpl::getVirtualWidgetTreeByClassName(
    const std::string &className) const {
  throw std::logic_error("Not yet implemented");
  return nullptr;
}
} // namespace screen_reader