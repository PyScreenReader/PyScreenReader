#include "src/native/macos/screen_reader_impl_mac.h"

#include <stdexcept>


#include "src/native/macos/utils/system_utils.h"
#include "src/native/macos/vwidget_generator.h"
namespace screen_reader
{
    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
        // TODO: improve memory management
        if(pid.empty()) {
            throw std::invalid_argument("PID cannot be empty");
        }

        AXUIElementRef axuiElement = SystemUtils::getAXUIElementRefByPID(pid);
        if(!axuiElement) {
            throw std::runtime_error("Failed to create AXUIElement");
        }

        std::shared_ptr<VirtualRootWidget> root = generator::generateVWidgetTree(axuiElement);
        CFRelease(axuiElement);
        return root;
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
        throw std::logic_error("Not yet implemented");
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string &className) const {
        throw std::logic_error("Not yet implemented");
    }
}