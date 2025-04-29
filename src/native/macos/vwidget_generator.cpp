#include <queue>
#include <utility>
#include "include/vwidget/widgets/virtual_root_widget.h"
#include "src/native/macos/vwidget_generator.h"
#include "src/native/macos/utils/attribute_utils.h"

namespace generator
{
    using namespace AttributeUtils;

    std::shared_ptr<VirtualWidget> generator::handleStaticText(AXUIElementRef element) {
        auto result = std::make_shared<VirtualTextWidget>();

        getAXAttribute<CFStringRef, std::string>(
                element,
                kAXValueAttribute,
                convertCFStringToCPPString,
                [&](const std::string& text) {
                    result->setTitleText(text);
                }
        );

        return result;
    }

    std::shared_ptr<VirtualWidget> generator::handleUnknown(AXUIElementRef element) {
        return std::make_shared<VirtualUnknownWidget>();
    }

    std::shared_ptr<VirtualWidget> generator::handleButtonLiked(AXUIElementRef element) {
        auto result = std::make_shared<VirtualButtonWidget>();
        if (!getAXAttribute<CFStringRef, std::string>(
                element,
                kAXTitleAttribute,
                convertCFStringToCPPString,
                [&](const std::string& title) {
                    result->setTitleText(title);
                })) {
            // if there is no kAXTitleAttribute, let's also try kAXValueAttribute
            getAXAttribute<CFStringRef, std::string>(
                    element,
                    kAXValueAttribute,
                    convertCFStringToCPPString,
                    [&](const std::string& value) {
                        result->setTitleText(value);
                    });
        }
        return result;
    }

    std::shared_ptr<VirtualRootWidget> generator::generateVWidgetTree(AXUIElementRef rootElement) {
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

        auto root = std::dynamic_pointer_cast<VirtualRootWidget>(generator::getVWidget(rootElement));
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
            CFRelease(curr);
        }
        return root;
    }

    std::shared_ptr<VirtualWidget> generator::getVWidget(AXUIElementRef element) {
        CFRef<CFStringRef> roleName;
        CFStringRef rawRole = nullptr;
        safeGetAttribute(element, kAXRoleAttribute, &rawRole);
        roleName.reset(rawRole);

        if (!roleName) return nullptr;

        std::string plainRoleName;
        if (!convertCFStringToCPPString(roleName.get(), plainRoleName)) {
            return nullptr;
        }

        auto it = ROLE_TO_VWIDGET_MAP.find(plainRoleName);
        if (it == ROLE_TO_VWIDGET_MAP.end()) {
            return nullptr;
        }

        std::shared_ptr<VirtualWidget> result = it->second(element);

        getAXAttribute<CFBooleanRef, bool>(
                element,
                kAXHiddenAttribute,
                [](CFBooleanRef ref, bool& out) {
                    out = !CFBooleanGetValue(ref); // Negated for visible
                    return true;
                },
                [&](bool isVisible) {
                    result->setVisible(isVisible);
                }
        );

        getAXAttribute<CFStringRef, std::string>(
                element,
                kAXHelpAttribute,
                convertCFStringToCPPString,
                [&](const std::string& helpText) {
                    result->setHelpText(helpText);
                }
        );

        getAXAttribute<CFStringRef, std::string>(
                element,
                kAXTitleAttribute,
                convertCFStringToCPPString,
                [&](const std::string& title) {
                    result->setTitleText(title);
                }
        );

        return result;
    }
}