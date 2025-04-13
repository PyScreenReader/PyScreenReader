#pragma once
#include <memory>
#include <string>

#include "include/vwidget/widgets/virtual_root_widget.h"

class ScreenReaderImpl
{
public:
    ScreenReaderImpl() = default;
    ~ScreenReaderImpl() = default;
    static std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string& pid) const;
    static std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string& title) const;
    static std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string& className) const;
};
