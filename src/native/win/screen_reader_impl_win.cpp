#include "src/native/win/screen_reader_impl_win.h"

#include <oleacc.h>
#include <uiautomationcore.h>
#include <uiautomationcoreapi.h>
#include <windows.h>
#include <queue>
#include <stdexcept>
#include "src/native/win/vwidget_generator_win.h"

namespace screen_reader {

ScreenReaderImpl::ScreenReaderImpl() : automation_(nullptr), root_element_(nullptr) {
  HRESULT hresult = CoInitialize(nullptr);
  if (FAILED(hresult)) {
    throw std::runtime_error("Failed to initialize COM");
  }

  hresult = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER, IID_IUIAutomation,
                             reinterpret_cast<void**>(&automation_));
  if (FAILED(hresult)) {
    CoUninitialize();
    throw std::runtime_error("Failed to create UI Automation instance, terminating.");
  }
  hresult = automation_->GetRootElement(&root_element_);
  if (FAILED(hresult) || root_element_ == nullptr)
    throw std::runtime_error("Failed to get root element");
}

ScreenReaderImpl::~ScreenReaderImpl() {
  if (root_element_ != nullptr) {
    root_element_->Release();
    root_element_ = nullptr;
  }
  if (automation_ != nullptr) {
    automation_->Release();
    automation_ = nullptr;
    CoUninitialize();
  }
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByPID(
    const std::string& pid) const {
  if (pid.empty())
    throw std::invalid_argument("PID cannot be empty");

  VARIANT var_prop;
  var_prop.vt = VT_INT;
  var_prop.intVal = std::stoi(pid);

  IUIAutomationCondition* match_condition = nullptr;
  IUIAutomationElement* matched_element = nullptr;
  // Find the top COM element with the matching PID
  HRESULT hresult =
      automation_->CreatePropertyCondition(UIA_ProcessIdPropertyId, var_prop, &match_condition);
  if (FAILED(hresult) || match_condition == nullptr)
    throw std::runtime_error("Failed CreatePropertyCondition");
  hresult = root_element_->FindFirst(TreeScope_Children, match_condition, &matched_element);
  if (FAILED(hresult) || matched_element == nullptr)
    throw std::runtime_error("Failed could not find process");

  IUIAutomationTreeWalker* tree_walker = nullptr;
  hresult = automation_->get_ContentViewWalker(&tree_walker);
  if (FAILED(hresult))
    throw std::runtime_error("Failed could not get tree walker");

  std::shared_ptr<VirtualRootWidget> root =
      generator::GenerateVWidgetTree(matched_element, tree_walker);

  matched_element->Release();
  match_condition->Release();
  tree_walker->Release();
  return root;
}

// NOLINTBEGIN(readability-convert-member-functions-to-static)
std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByTitle(
    const std::string& title) const {
  throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReaderImpl::GetVirtualWidgetTreeByClassName(
    const std::string& class_name) const {
  throw std::logic_error("Not yet implemented");
}
// NOLINTEND(readability-convert-member-functions-to-static)
}  // namespace screen_reader
