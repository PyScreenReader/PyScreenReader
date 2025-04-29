#pragma once
#include <memory>
#include <string>

#include "include/vwidget/widgets/virtual_root_widget.h"

namespace screen_reader
{
    class ScreenReaderImpl
    {
    public:
        ScreenReaderImpl() = default;
        ~ScreenReaderImpl() = default;
        std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string& pid) const;
        std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string& title) const;
        std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string& className) const;
    };
}
