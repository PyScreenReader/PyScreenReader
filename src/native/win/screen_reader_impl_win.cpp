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

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByPID(const std::string& pid) const
    {
        if (pid.empty()) throw std::invalid_argument("PID cannot be empty");

        VARIANT varProp;
        varProp.vt = VT_INT;
        varProp.intVal = std::stoi(pid);

        IUIAutomationCondition* match_condition = nullptr;
        IUIAutomationElement* matched_element = nullptr;
        // Find the top COM element with the matching PID
        HRESULT hr = automation_->CreatePropertyCondition(UIA_ProcessIdPropertyId, varProp, &match_condition);
        if (FAILED(hr) || !match_condition) throw std::runtime_error("Failed CreatePropertyCondition");
        hr = root_element_->FindFirst(TreeScope_Children, match_condition, &matched_element);
        if (FAILED(hr) || !matched_element) throw std::runtime_error("Failed could not find process");

        IUIAutomationTreeWalker* tree_walker = nullptr;
        hr = automation_->get_ContentViewWalker(&tree_walker);
        if (FAILED(hr)) throw std::runtime_error("Failed could not get tree walker");

        std::shared_ptr<VirtualRootWidget> root = generator::GenerateVWidgetTree(
            matched_element, tree_walker);

        matched_element->Release();
        match_condition->Release();
        tree_walker->Release();
        return root;
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByTitle(const std::string& title) const
    {
        throw std::logic_error("Not yet implemented");
    }

    std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::getVirtualWidgetTreeByClassName(const std::string& class_name) const
    {
        throw std::logic_error("Not yet implemented");
    }
}
