#include <queue>
#include <utility>
#include "include/vwidget/widgets/virtual_root_widget.h"
#include "src/native/macos/vwidget_generator.h"
#include "src/native/macos/utils/attribute_utils.h"

namespace generator
{

    std::shared_ptr<VirtualWidget> generator::HandleStaticText(AXUIElementRef element) {
        auto result = std::make_shared<VirtualTextWidget>();

        attribute_utils::GetAXAttribute<CFStringRef, std::string>(
                element,
                kAXValueAttribute,
                attribute_utils::ConvertCFStringToCPPString,
                [result](const std::string &text) {
                    result->SetTitleText(text);
                }
        );

        return result;
    }

    std::shared_ptr<VirtualWidget> generator::HandleUnknown(AXUIElementRef element) {
        return std::make_shared<VirtualUnknownWidget>();
    }

    std::shared_ptr<VirtualWidget> generator::HandleButtonLiked(AXUIElementRef element) {
        auto result = std::make_shared<VirtualButtonWidget>();
        if (!attribute_utils::GetAXAttribute<CFStringRef, std::string>(
                element,
                kAXTitleAttribute,
                attribute_utils::ConvertCFStringToCPPString,
                [result](const std::string &title) {
                    result->SetTitleText(title);
                })) {
            // if there is no kAXTitleAttribute, let's also try kAXValueAttribute
            attribute_utils::GetAXAttribute<CFStringRef, std::string>(
                    element,
                    kAXValueAttribute,
                    attribute_utils::ConvertCFStringToCPPString,
                    [result](const std::string &value) {
                        result->SetTitleText(value);
                    });
        }
        return result;
    }

    std::shared_ptr<VirtualRootWidget> generator::GenerateVWidgetTree(AXUIElementRef rootElement) {
        auto process_children = [](AXUIElementRef element, auto&& enqueueFunc) {
            CFArrayRef children = nullptr;
            if (!attribute_utils::SafeGetAttribute(element, kAXChildrenAttribute, reinterpret_cast<CFTypeRef *>(&children))
                || !children
                || CFArrayGetCount(children) == 0) {
                return;
            }

            std::unique_ptr<std::remove_pointer_t<CFTypeRef>, decltype(&CFRelease)> children_guard(reinterpret_cast<CFTypeRef>(children), CFRelease);

            const CFIndex count = CFArrayGetCount(children);
            for (CFIndex i = 0; i < count; ++i) {
                const auto *child = static_cast<AXUIElementRef>(CFArrayGetValueAtIndex(children, i));
                CFRetain(child);
                enqueueFunc(child);
            }
        };

        auto root = std::dynamic_pointer_cast<VirtualRootWidget>(generator::GetVWidget(rootElement));
        std::queue<std::pair<std::shared_ptr<VirtualWidget>, AXUIElementRef>> queue;
        process_children(rootElement, [root, &queue](AXUIElementRef child) {
            queue.emplace(root, child);
        });

        while (!queue.empty()) {
            auto [parentVWidget, curr] = queue.front();
            queue.pop();

            auto curr_vwidget = GetVWidget(curr);

            if (curr_vwidget == nullptr) {
                continue;
            }
            curr_vwidget->SetParent(parentVWidget);
            parentVWidget->AddChild(curr_vwidget);

            if (!parentVWidget->IsVisible()) {
                curr_vwidget->SetVisible(false);
            }
            process_children(curr, [curr_vwidget, &queue](AXUIElementRef child) {
                queue.emplace(curr_vwidget, child);
            });
            CFRelease(curr);
        }
        return root;
    }

    std::shared_ptr<VirtualWidget> generator::GetVWidget(AXUIElementRef element) {
        attribute_utils::CFRef<CFStringRef> role_name;
        CFStringRef raw_role = nullptr;
        attribute_utils::SafeGetAttribute(element, kAXRoleAttribute, &raw_role);
        role_name.reset(raw_role);

        std::string plain_role_name;
        if (!attribute_utils::ConvertCFStringToCPPString(role_name.get(), plain_role_name)) {
            return nullptr;
        }

        auto iter = ROLE_TO_VWIDGET_MAP.find(plain_role_name);
        if (iter == ROLE_TO_VWIDGET_MAP.end()) {
            return nullptr;
        }

        std::shared_ptr<VirtualWidget> result = iter->second(element);

        attribute_utils::GetAXAttribute<CFBooleanRef, bool>(
                element,
                kAXHiddenAttribute,
                [](CFBooleanRef ref, bool &out) {
                    out = !CFBooleanGetValue(ref); // Negated for visible
                    return true;
                },
                [result](bool isVisible) {
                    result->SetVisible(isVisible);
                }
        );

        attribute_utils::GetAXAttribute<CFStringRef, std::string>(
                element,
                kAXHelpAttribute,
                attribute_utils::ConvertCFStringToCPPString,
                [result](const std::string &helpText) {
                    result->SetHelpText(helpText);
                }
        );

        attribute_utils::GetAXAttribute<CFStringRef, std::string>(
                element,
                kAXTitleAttribute,
                attribute_utils::ConvertCFStringToCPPString,
                [result](const std::string &title) {
                    result->SetTitleText(title);
                }
        );

        return result;
    }
}  // namespace generator