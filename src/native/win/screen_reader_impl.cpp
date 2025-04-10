#include "native/macos/screen_reader_impl.h"

#include <stdexcept>

#include "native/macos/utils/system_utils.h"
#include "native/macos/vwidget_generator.h"

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
    return nullptr;
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string &className) const {
    throw std::logic_error("Not yet implemented");
}