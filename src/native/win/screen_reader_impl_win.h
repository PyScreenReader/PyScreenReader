#pragma once
#include <memory>

#include <windows.h>
#include <oleacc.h>
#include <uiautomationclient.h>
#include <uiautomationcore.h>
#include <uiautomationcoreapi.h>

#include <string>
#include "vwidget/widgets/virtual_root_widget.h"

class ScreenReaderImpl {
public:
    ScreenReaderImpl() = default;
    ~ScreenReaderImpl() = default;
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string &pid) const;
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string &title) const;
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string &className) const;
};