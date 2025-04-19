#include "src/native/win/screen_reader_impl_win.h"

#include <stdexcept>
#include "src/native/win/vwidget_generator_win.h"
#include <windows.h>
#include <uiautomationcore.h>
#include <uiautomationcoreapi.h>
#include <oleacc.h>


ScreenReaderImpl::ScreenReaderImpl() : automation_(nullptr)
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
}

ScreenReaderImpl::~ScreenReaderImpl()
{
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
        pNode->get_CurrentLocalizedControlType(&type);
        pNode->get_CurrentName(&name);
        for (int x = 0; x <= indent; x++)
        {
            printf("   ");
        }
        printf("%S --> %S \n", type, name);
        SysFreeString(type);
        SysFreeString(name);

        ListDescendants(pNode, indent+1, depth-1);
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
    IUIAutomationElement* pRootElement = nullptr;
    HRESULT hr = automation_->GetRootElement(&pRootElement);
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to get root element");
    }
    if (!pRootElement) throw std::runtime_error("nullptr root element");

    ListDescendants(pRootElement, 0, 2);
    // TODO: Process the root element and create virtual widget tree

    // Cleanup
    pRootElement->Release();
    return std::make_shared<VirtualRootWidget>();;
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string& title) const
{
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string& className) const
{
    throw std::logic_error("Not yet implemented");
}
