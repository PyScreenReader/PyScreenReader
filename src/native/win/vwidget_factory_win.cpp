#include "vwidget_factory_win.h"
#include <comutil.h>

template <>
std::shared_ptr<VirtualButtonWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualButtonWidget>(element);
}

template <>
std::shared_ptr<VirtualTextWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualTextWidget>(element);
}

template <>
std::shared_ptr<VirtualTextInputWidget> vwidget_factory::CreateWidget(
    IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualTextInputWidget>(element);
}

template <>
std::shared_ptr<VirtualMenuWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuWidget>(element);
}

template <>
std::shared_ptr<VirtualMenuItemWidget> vwidget_factory::CreateWidget(
    IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuItemWidget>(element);
}

template <>
std::shared_ptr<VirtualWindowWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualWindowWidget>(element);
}

template <>
std::shared_ptr<VirtualGroupWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualGroupWidget>(element);
}

template <>
std::shared_ptr<VirtualUnknownWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualUnknownWidget>(element);
}

template <>
std::shared_ptr<VirtualScrollbarWidget> vwidget_factory::CreateWidget(
    IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualScrollbarWidget>(element);
}

template <>
std::shared_ptr<VirtualSliderWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSliderWidget>(element);
}

template <>
std::shared_ptr<VirtualProgressBarWidget> vwidget_factory::CreateWidget(
    IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualProgressBarWidget>(element);
}

template <>
std::shared_ptr<VirtualSpinnerWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSpinnerWidget>(element);
}

/**
 * Populate shared attributes across all the virtual widgets.
 * These shared attributes (e.g. title, dimensions) are defined in @see virtual_widget.h,
 * which is the parent class of all the derived virtual widgets.
 *
 * These populated values might be overwritten later in the handlers of each specific widgets.
 *
 * @param widget any type of virtual widget
 * @param element native IUIAutomationElement* to copy the values from
 * @note this function modifies the param widget
 */
void vwidget_factory::PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget,
                                               IUIAutomationElement* element) {
  HRESULT hresult = S_OK;
  // Title
  BSTR current_name = nullptr;
  hresult = element->get_CurrentName(&current_name);
  if (current_name && SUCCEEDED(hresult)) {
    const std::string title_string(_com_util::ConvertBSTRToString(current_name));
    widget->SetTitleText(title_string);
  }
  SysFreeString(current_name);
  current_name = nullptr;

  // Native name
  BSTR control_type = nullptr;
  hresult = element->get_CurrentLocalizedControlType(&control_type);
  if (control_type && SUCCEEDED(hresult)) {
    const std::string title_string(_com_util::ConvertBSTRToString(control_type));
    widget->SetNativeName(title_string);
  }
  SysFreeString(control_type);
  control_type = nullptr;

  // Help text
  BSTR help_text = nullptr;
  hresult = element->get_CurrentHelpText(&help_text);
  if (help_text && SUCCEEDED(hresult)) {
    const std::string title_string(_com_util::ConvertBSTRToString(help_text));
    widget->SetHelpText(title_string);
  }
  SysFreeString(help_text);
  help_text = nullptr;

  // Position and Dimension (Width and Height)
  RECT rect;
  hresult = element->get_CurrentBoundingRectangle(&rect);
  if (SUCCEEDED(hresult)) {
    widget->SetX(static_cast<int>(rect.left));
    widget->SetY(static_cast<int>(rect.top));
    widget->SetWidth(static_cast<int>(rect.right - rect.left));
    widget->SetHeight(static_cast<int>(rect.bottom - rect.top));
  }

  // Focus
  BOOL is_focused = FALSE;
  hresult = element->get_CurrentHasKeyboardFocus(&is_focused);
  if (SUCCEEDED(hresult)) {
    widget->SetFocused(static_cast<bool>(is_focused));
  }
}