#pragma once
#include <memory>
#include <string>

#include "include/vwidget/virtual_widget.h"

namespace screen_reader
{
    class ScreenReaderImpl
    {
    public:
        ScreenReaderImpl() = default;
        ~ScreenReaderImpl() = default;

        std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByPID(const std::string& pid) const;
        std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByTitle(const std::string& title) const;
        std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByClassName(const std::string& class_name) const;
    };
}
