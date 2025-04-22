#include "src/native/win/vwidget_generator_win.h"

#include <queue>
#include <utility>

std::shared_ptr<VirtualRootWidget> VWidgetGenerator::generateVWidgetTree(IUIAutomationElement* rootElement) {
    auto root = std::make_shared<VirtualRootWidget>();
    std::queue<std::pair<std::shared_ptr<VirtualWidget>, IUIAutomationElement*>> q;

    q.emplace(root, rootElement);

    while (!q.empty()) {
        auto [parentVWidget, curr] = q.front();
        q.pop();

        auto currVWidget = getVWidget(curr);
        if (currVWidget == nullptr) continue;
        currVWidget->setParent(parentVWidget);
        parentVWidget->addChild(currVWidget);

        if (!parentVWidget->isVisible()) currVWidget->setVisible(false);

        // CFArrayRef cfChildrenArray = nullptr;
        // if (!safeGetAttribute(curr, kAXChildrenAt    tribute, &cfChildrenArray)) continue;
        //
        // CFIndex count = CFArrayGetCount(cfChildrenArray);
        // for (CFIndex i = 0; i < count; i++) {
        //     auto child = (AXUIElementRef) CFArrayGetValueAtIndex(cfChildrenArray, i);
        //     q.emplace(currVWidget, child);
        // }
    }
    return root;
}

std::shared_ptr<VirtualWidget> VWidgetGenerator::getVWidget(IUIAutomationElement* element) {
    auto result = nullptr;
    return result;
}

