#include "native/win/screen_reader_impl_win.h"

#include <stdexcept>
#include "native/win/vwidget_generator_win.h"

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string &pid) const {
    return nullptr;
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string &title) const {
    throw std::logic_error("Not yet implemented");
    return nullptr;
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string &className) const {
    throw std::logic_error("Not yet implemented");
    return nullptr;
}