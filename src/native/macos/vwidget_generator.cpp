#include <queue>
#include <utility>
#include "vwidget/widgets/virtual_root_widget.h"
#include "native/macos/vwidget_generator.h"
#include "native/macos/utils/attribute_utils.h"



std::shared_ptr<VirtualRootWidget> VWidgetGenerator::generateVWidgetTree(AXUIElementRef rootElement) {
    auto root = std::make_shared<VirtualRootWidget>();
    std::queue<std::pair<std::shared_ptr<VirtualWidget>, AXUIElementRef>> q;

    q.emplace(root, rootElement);

    while (!q.empty()) {
        auto [parentVWidget, curr] = q.front();
        q.pop();

        auto currVWidget = getVWidget(curr);
        if (currVWidget == nullptr) continue;
        currVWidget->setParent(parentVWidget);
        parentVWidget->addChild(currVWidget);

        if (!parentVWidget->isVisible()) currVWidget->setVisible(false);

        CFArrayRef cfChildrenArray = nullptr;
        if (!safeGetAttribute(curr, kAXChildrenAttribute, &cfChildrenArray)) continue;

        CFIndex count = CFArrayGetCount(cfChildrenArray);
        for (CFIndex i = 0; i < count; i++) {
            auto child = (AXUIElementRef) CFArrayGetValueAtIndex(cfChildrenArray, i);
            q.emplace(currVWidget, child);
        }
    }
    return root;
}

std::shared_ptr<VirtualWidget> VWidgetGenerator::getVWidget(AXUIElementRef element) {
    CFStringRef roleName = nullptr;
    safeGetAttribute(element, kAXRoleAttribute, &roleName);

    // If there is no role name for some reason, we can ignore
    if (roleName == nullptr) return nullptr;
    std::string plainRoleName;
    // If error when parsing role string, we skip
    if (!safeCFStringGetCString(roleName, plainRoleName)) return nullptr;

    std::shared_ptr<VirtualWidget> result;
    auto it = ROLE_TO_VWIDGET_MAP.find(plainRoleName);
    if (it != ROLE_TO_VWIDGET_MAP.end()) {
        // call the corresponding handler to create virtual widget
        result = it->second();

        CFBooleanRef isHidden = nullptr;
        CFStringRef helpText = nullptr;
        CFStringRef titleText = nullptr;

        bool hasHiddenAttribute = safeGetAttribute(element, kAXHiddenAttribute, &isHidden);
        bool hasHelpTextAttribute = safeGetAttribute(element, kAXHelpAttribute, &helpText);
        bool hasTitleTextAttribute = safeGetAttribute(element, kAXTitleAttribute, &titleText);

        if (hasHiddenAttribute) {
            result->setVisible(CFBooleanGetValue(isHidden));
            CFRelease(isHidden);
        }

        if (hasHelpTextAttribute) {
            std::string plainHelpText;
            safeCFStringGetCString(helpText, plainHelpText);
            result->setHelpText(plainHelpText);
            CFRelease(helpText);
        }

        if (hasTitleTextAttribute) {
            std::string plainTitleText;
            safeCFStringGetCString(titleText, plainTitleText);
            result->setHelpText(plainTitleText);
            CFRelease(titleText);
        }
    }

    if (roleName) {
        CFRelease(roleName);
    }

    return result;
}

