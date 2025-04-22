#pragma once
#include <memory>

#include <string>
#include "include/vwidget/widgets/virtual_root_widget.h"
#include <uiautomationclient.h>

class ScreenReaderImpl {
public:
    ScreenReaderImpl();
    ~ScreenReaderImpl();
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string &pid) const;
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string &title) const;
    [[nodiscard]] std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string &className) const;
private:
    // CAUTION: Do not pass in the root (desktop) element. Traversing the entire subtree
    // of the desktop could take a very long time and even lead to a stack overflow.
    void ListDescendants(IUIAutomationElement* pParent, int indent, int depth) const;
    std::unique_ptr<IUIAutomation> automation_;
    IUIAutomationElement* root_element_;
};