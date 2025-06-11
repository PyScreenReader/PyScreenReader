#include "src/native/macos/screen_reader_impl_mac.h"

#include <stdexcept>

namespace screen_reader {
std::shared_ptr<VirtualWidget> ScreenReaderImpl::GetVirtualWidgetTreeByPID(
    const std::string& pid) const {
  // FIXME (#27): uncomment the following until the refactoring is done

  //        if(pid.empty()) {
  //            throw std::invalid_argument("PID cannot be empty");
  //        }
  //
  //        AXUIElementRef axui_element = SystemUtils::GetAXUIElementRefByPID(pid);
  //        if(axui_element == nullptr) {
  //            throw std::runtime_error("Failed to create AXUIElement");
  //        }
  //
  //        std::shared_ptr<VirtualRootWidget> root = generator::GenerateVWidgetTree(axui_element);
  //        CFRelease(axui_element);
  //        return root;
  throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualWidget> ScreenReaderImpl::GetVirtualWidgetTreeByTitle(
    const std::string& title) const {
  throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualWidget> ScreenReaderImpl::GetVirtualWidgetTreeByClassName(
    const std::string& class_name) const {
  throw std::logic_error("Not yet implemented");
}
}  // namespace screen_reader