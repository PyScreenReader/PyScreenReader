#pragma once
#include <memory>

#include <string>
#include "include/vwidget/widgets/virtual_root_widget.h"
#include <uiautomationclient.h>

namespace screen_reader
{
    class ScreenReaderImpl {
    public:
        ScreenReaderImpl();
        ~ScreenReaderImpl();
        [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string &pid) const;
        [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string &title) const;
        [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string &class_name) const;
    private:
        IUIAutomation* automation_;
        IUIAutomationElement* root_element_;
    };
}