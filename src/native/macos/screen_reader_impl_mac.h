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

        // TODO(#30) the linter suppression could be removed until the issue is implemented
        // NOLINTBEGIN(readability-convert-member-functions-to-static)
        std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByPID(const std::string& pid) const;
        std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByTitle(const std::string& title) const;
        std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByClassName(const std::string& class_name) const;
        // NOLINTEND(readability-convert-member-functions-to-static)
    };
}
