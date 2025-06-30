#include "src/native/macos/screen_reader_impl_mac.h"
#include "src/native/macos/utils/system_utils.h"
#include "src/native/macos/vwidget_generator.h"

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <stdexcept>

namespace screen_reader {
std::shared_ptr<VirtualWidget> ScreenReaderImpl::GetVirtualWidgetTreeByPID(
    const std::string& pid) {
  if (pid.empty()) {
    throw std::invalid_argument("PID cannot be empty");
  }

  AXUIElementRef axui_element = system_utils::GetAXUIElementRefByPID(pid);
  if (axui_element == nullptr) {
    throw std::runtime_error("Failed to create AXUIElement");
  }

  std::shared_ptr<VirtualWidget> root = vwidget_generator::GenerateVWidgetTree(axui_element);
  CFRelease(axui_element);
  return root;
}
}  // namespace screen_reader