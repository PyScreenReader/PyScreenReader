#include "src/native/macos/screen_reader_impl_mac.h"

#include <stdexcept>


#include "src/native/macos/utils/system_utils.h"
#include "src/native/macos/vwidget_generator.h"

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) {
    // TODO: improve memory management
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

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) {
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string &className) {
    throw std::logic_error("Not yet implemented");
}