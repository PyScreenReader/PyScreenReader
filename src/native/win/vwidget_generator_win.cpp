#include "src/native/win/vwidget_generator_win.h"

#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>

#include "include/vwidget/widgets/virtual_window_widget.h"

namespace generator
{
    std::shared_ptr<VirtualRootWidget> generator::GenerateVWidgetTree(
        IUIAutomationElement* root_element, IUIAutomationTreeWalker* tree_walker)
    {
        auto root = std::make_shared<VirtualRootWidget>();
        std::queue<std::pair<std::shared_ptr<VirtualWidget>, IUIAutomationElement*>> q;
        q.emplace(root, root_element);
        HRESULT hr = S_OK;
        while (!q.empty())
        {
            // This is the first child of the clade
            auto [parent_vwidget, curr] = q.front();
            q.pop();

            std::shared_ptr<VirtualWidget> curr_vwidget = nullptr;
            IUIAutomationElement* current_element = curr;
            IUIAutomationElement* first_child_element = nullptr;
            while (current_element)
            {
                // Check next sibling, add their first child to queue and bind parent/child
                curr_vwidget = CreateVirtualWidget(current_element);
                curr_vwidget->setParent(parent_vwidget);
                parent_vwidget->addChild(curr_vwidget);
                tree_walker->GetFirstChildElement(current_element, &first_child_element);
                if (first_child_element)
                {
                    q.emplace(curr_vwidget, first_child_element);
                }
                hr = tree_walker->GetNextSiblingElement(current_element, &current_element);
                if (FAILED(hr)) throw std::runtime_error("Failed GetNextSiblingElement");
            }
        }
        return root;
    }

    std::shared_ptr<VirtualWidget> generator::CreateVirtualWidget(IUIAutomationElement* element)
    {
        return std::make_shared<VirtualWindowWidget>();
    }
}
