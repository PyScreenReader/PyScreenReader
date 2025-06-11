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
    };
}
