#include "src/native/macos/screen_reader_impl_mac.h"
#include "src/native/macos/utils/system_utils.h"
#include "src/native/macos/utils/cf_utils.h"
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

  // Perform a sanity check by confirm if we can read the role id of the root node
  auto root_role_id_opt = cf_utils::GetAttribute<std::string>(axui_element, kAXRoleAttribute);

  if (!root_role_id_opt.has_value())
    throw std::runtime_error("Failed to create AXUIElement - the process might not exist or this program does not have permission");

  std::shared_ptr<VirtualWidget> root = vwidget_generator::GenerateVWidgetTree(axui_element);
  CFRelease(axui_element);
  return root;
}
}  // namespace screen_reader