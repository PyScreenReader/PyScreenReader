#include <queue>
#include <utility>
#include "include/vwidget/widgets/virtual_root_widget.h"
#include "src/native/macos/vwidget_generator.h"
#include "src/native/macos/utils/attribute_utils.h"


std::shared_ptr<VirtualRootWidget> VWidgetGenerator::generateVWidgetTree(AXUIElementRef rootElement) {
    auto processChildren = [](AXUIElementRef element, auto&& enqueueFunc) {
        CFArrayRef children = nullptr;
        if (!safeGetAttribute(element, kAXChildrenAttribute, (CFTypeRef*)&children)
            || !children
            || CFArrayGetCount(children) == 0) {
            return;
        }

        std::unique_ptr<std::remove_pointer_t<CFTypeRef>, decltype(&CFRelease)> childrenGuard(reinterpret_cast<CFTypeRef>(children), CFRelease);

        const CFIndex count = CFArrayGetCount(children);
        for (CFIndex i = 0; i < count; ++i) {
            auto child = static_cast<AXUIElementRef>(CFArrayGetValueAtIndex(children, i));
            CFRetain(child);
            enqueueFunc(child);
        }
    };

    auto root = std::dynamic_pointer_cast<VirtualRootWidget>(VWidgetGenerator::getVWidget(rootElement));
    std::queue<std::pair<std::shared_ptr<VirtualWidget>, AXUIElementRef>> q;
    processChildren(rootElement, [&](AXUIElementRef child) {
        q.emplace(root, child);
    });

    while (!q.empty()) {
        auto [parentVWidget, curr] = q.front();
        q.pop();

        auto currVWidget = getVWidget(curr);
        if (currVWidget == nullptr) continue;
        currVWidget->setParent(parentVWidget);
        parentVWidget->addChild(currVWidget);

        if (!parentVWidget->isVisible()) currVWidget->setVisible(false);
        processChildren(curr, [&](AXUIElementRef child) {
            q.emplace(currVWidget, child);
        });
    }
    return root;
}

std::shared_ptr<VirtualWidget> VWidgetGenerator::getVWidget(AXUIElementRef element) {
    CFRef<CFStringRef> roleName;
    CFStringRef rawRole = nullptr;
    safeGetAttribute(element, kAXRoleAttribute, &rawRole);
    roleName.reset(rawRole);

    if (!roleName) return nullptr;

    std::string plainRoleName;
    if (!safeCFStringGetCString(roleName.get(), plainRoleName)) {
        return nullptr;
    }

    auto it = ROLE_TO_VWIDGET_MAP.find(plainRoleName);
    if (it == ROLE_TO_VWIDGET_MAP.end()) {
        return nullptr;
    }

    std::shared_ptr<VirtualWidget> result = it->second();

    CFRef<CFBooleanRef> isHidden;
    CFRef<CFStringRef> helpText;
    CFRef<CFStringRef> titleText;

    CFBooleanRef rawHidden = nullptr;
    if (safeGetAttribute(element, kAXHiddenAttribute, &rawHidden)) {
        isHidden.reset(rawHidden);
        result->setVisible(!CFBooleanGetValue(isHidden.get()));
    }

    CFStringRef rawHelp = nullptr;
    if (safeGetAttribute(element, kAXHelpAttribute, &rawHelp)) {
        helpText.reset(rawHelp);
        std::string plainHelpText;
        if (safeCFStringGetCString(helpText.get(), plainHelpText)) {
            result->setHelpText(plainHelpText);
        }
    }

    CFStringRef rawTitle = nullptr;
    if (safeGetAttribute(element, kAXTitleAttribute, &rawTitle)) {
        titleText.reset(rawTitle);
        std::string plainTitleText;
        if (safeCFStringGetCString(titleText.get(), plainTitleText)) {
            result->setTitleText(plainTitleText);
        }
    }

    return result;
}
