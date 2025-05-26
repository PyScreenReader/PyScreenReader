#include "src/native/macos/screen_reader_impl_mac.h"

#include <stdexcept>


#include "src/native/macos/utils/system_utils.h"
#include "src/native/macos/vwidget_generator.h"
namespace screen_reader
{
    // TODO(#30) the linter suppression could be removed until the issue is implemented
    // NOLINTBEGIN(readability-convert-member-functions-to-static)
    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByPID(const std::string &pid) const {
        if(pid.empty()) {
            throw std::invalid_argument("PID cannot be empty");
        }

        AXUIElementRef axui_element = SystemUtils::GetAXUIElementRefByPID(pid);
        if(axui_element == nullptr) {
            throw std::runtime_error("Failed to create AXUIElement");
        }

        std::shared_ptr<VirtualRootWidget> root = generator::GenerateVWidgetTree(axui_element);
        CFRelease(axui_element);
        return root;
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByTitle(const std::string &title) const {
        throw std::logic_error("Not yet implemented");
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByClassName(const std::string &class_name) const {
        throw std::logic_error("Not yet implemented");
    }
    // NOLINTEND(readability-convert-member-functions-to-static)
}  // namespace screen_reader