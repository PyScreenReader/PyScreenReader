#include "src/native/win/screen_reader_impl_win.h"

#include <stdexcept>
#include "src/native/win/vwidget_generator_win.h"
#include <windows.h>
#include <uiautomationcore.h>
#include <uiautomationcoreapi.h>
#include <oleacc.h>
#include <queue>

namespace screen_reader
{
    ScreenReaderImpl::ScreenReaderImpl() : automation_(nullptr), root_element_(nullptr)
    {
        HRESULT hr = CoInitialize(nullptr);
        if (FAILED(hr))
        {
            throw std::runtime_error("Failed to initialize COM");
        }

        hr = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER,
                              IID_IUIAutomation, reinterpret_cast<void**>(&automation_));
        if (FAILED(hr))
        {
            CoUninitialize();
            throw std::runtime_error("Failed to create UI Automation instance, terminating.");
        }
        hr = automation_->GetRootElement(&root_element_);
        if (FAILED(hr) || !root_element_) throw std::runtime_error("Failed to get root element");
    }

    ScreenReaderImpl::~ScreenReaderImpl()
    {
        if (root_element_ != nullptr)
        {
            root_element_->Release();
            root_element_ = nullptr;
        }
        if (automation_ != nullptr)
        {
            automation_->Release();
            automation_ = nullptr;
            CoUninitialize();
        }
    }

    void ScreenReaderImpl::ListDescendants(IUIAutomationElement* pParent, int indent, int depth) const
    {
        if (pParent == nullptr || depth <= 0)
            return;

        IUIAutomationTreeWalker* pControlWalker = nullptr;
        IUIAutomationElement* pNode = nullptr;

        automation_->get_ControlViewWalker(&pControlWalker);
        if (pControlWalker == nullptr) return;

        pControlWalker->GetFirstChildElement(pParent, &pNode);
        if (pNode == nullptr)
        {
            if (pControlWalker != nullptr)
                pControlWalker->Release();
            return;
        }

        while (pNode)
        {
            BSTR type;
            BSTR name;
            CONTROLTYPEID type_id;
            int pid;
            pNode->get_CurrentLocalizedControlType(&type);
            pNode->get_CurrentName(&name);
            pNode->get_CurrentProcessId(&pid);
            pNode->get_CurrentControlType(&type_id);

            for (int x = 0; x <= indent; x++)
            {
                printf("   ");
            }
            printf("%S --> %S, TypeID: %d, PID: %d \n", type, name, type_id, pid);
            SysFreeString(type);
            SysFreeString(name);

            ListDescendants(pNode, indent + 1, depth - 1);
            IUIAutomationElement* pNext;
            pControlWalker->GetNextSiblingElement(pNode, &pNext);
            pNode->Release();
            pNode = pNext;
        }
        if (pControlWalker != nullptr)
            pControlWalker->Release();
        if (pNode != nullptr)
            pNode->Release();
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string& pid) const
    {
        if (pid.empty()) throw std::invalid_argument("PID cannot be empty");

        VARIANT varProp;
        varProp.vt = VT_INT;
        varProp.intVal = std::stoi(pid);

        // Find the top COM element with the matching PID
        IUIAutomationCondition* pid_condition;
        IUIAutomationElement* pid_match = nullptr;
        HRESULT hr = automation_->CreatePropertyCondition(UIA_ProcessIdPropertyId, varProp, &pid_condition);
        if (FAILED(hr) || !pid_condition) throw std::runtime_error("Failed CreatePropertyCondition");
        hr = root_element_->FindFirst(TreeScope_Children, pid_condition, &pid_match);
        if (FAILED(hr) || !pid_match) throw std::runtime_error("Failed could not find process");

        IUIAutomationTreeWalker* tree_walker = nullptr;
        automation_->get_ContentViewWalker(&tree_walker);

        std::shared_ptr<VirtualRootWidget> root = generator::GenerateVWidgetTree(
            pid_match, std::shared_ptr<IUIAutomationTreeWalker>(tree_walker));

        pid_match->Release();
        tree_walker->Release();
        return root;
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string& title) const
    {
        throw std::logic_error("Not yet implemented");
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string& className) const
    {
        throw std::logic_error("Not yet implemented");
    }
}
