#include "src/native/win/vwidget_generator_win.h"

#include <queue>
#include <stdexcept>
#include <utility>

#include "include/vwidget/widgets/virtual_window_widget.h"

namespace generator
{
    std::shared_ptr<VirtualRootWidget> generator::GenerateVWidgetTree(
        IUIAutomationElement* root_element, const std::shared_ptr<IUIAutomationTreeWalker>& tree_walker)
    {
        auto root = std::make_shared<VirtualRootWidget>();
        std::queue<std::pair<std::shared_ptr<VirtualWidget>, IUIAutomationElement*>> q;
        q.emplace(root, root_element);

        while (!q.empty())
        {
            // This is the first child of the clade
            auto [parent_vwidget, curr] = q.front();
            q.pop();

            std::shared_ptr<VirtualWidget> curr_vwidget = nullptr;
            IUIAutomationElement* next_sibling = curr;
            IUIAutomationElement* first_child_element = nullptr;
            while (next_sibling != nullptr)
            {
                // Check next sibling, add their first child to queue and bind parent/child
                curr_vwidget = MakeVWidget(next_sibling);
                curr_vwidget->setParent(parent_vwidget);
                parent_vwidget->addChild(curr_vwidget);

                if (S_OK == tree_walker->GetFirstChildElement(next_sibling, &first_child_element) &&
                    first_child_element)
                {
                    q.emplace(curr_vwidget, first_child_element);
                }
                tree_walker->GetNextSiblingElement(curr, &next_sibling);
            }
        }
        return root;
    }

    std::shared_ptr<VirtualWidget> generator::MakeVWidget(IUIAutomationElement* element)
    {
        return std::make_shared<VirtualWindowWidget>();
    }
}
