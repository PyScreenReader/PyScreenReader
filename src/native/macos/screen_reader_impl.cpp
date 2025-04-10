#include "native/macos/screen_reader_impl.h"

#include <stdexcept>
#if __APPLE__

#include "native/macos/utils/system_utils.h"
#include "native/macos/vwidget_generator.h"

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
    if(pid.empty()) {
        throw std::invalid_argument("PID cannot be empty");
    }

    AXUIElementRef axuiElement = SystemUtils::getAXUIElementRefByPID(pid);
    if(!axuiElement) {
        throw std::runtime_error("Failed to create AXUIElement");
    }

    std::shared_ptr<VirtualRootWidget> root = VWidgetGenerator::generateVWidgetTree(axuiElement);
    CFRelease(axuiElement);
    return root;
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string &className) const {
    throw std::logic_error("Not yet implemented");
}
#endif