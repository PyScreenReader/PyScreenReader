#pragma once
#include <memory>

#include <windows.h>
#include <string>
#include "vwidget/widgets/virtual_root_widget.h"

class ScreenReaderImpl {
public:
    ScreenReaderImpl() = default;
    ~ScreenReaderImpl() = default;
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string &pid) const;
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string &title) const;
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string &className) const;
};