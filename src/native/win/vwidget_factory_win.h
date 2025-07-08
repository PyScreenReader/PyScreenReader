#pragma once

#include <uiautomationclient.h>
#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_group_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_menu_widget.h"
#include "include/vwidget/widgets/virtual_progress_bar_widget.h"
#include "include/vwidget/widgets/virtual_scrollbar_widget.h"
#include "include/vwidget/widgets/virtual_slider_widget.h"
#include "include/vwidget/widgets/virtual_spinner_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"

#include <optional>

namespace vwidget_factory {
template <typename T>
std::shared_ptr<T> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualButtonWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualTextWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualTextInputWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualMenuWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualMenuItemWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualWindowWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualGroupWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualUnknownWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualScrollbarWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualSliderWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualProgressBarWidget> CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualSpinnerWidget> CreateWidget(IUIAutomationElement* element);

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
void PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget, IUIAutomationElement* element);

/**
 * Create virtual widget corresponds to the given IUIAutomationElement*
 * with basic non-specific attributes populated.
 *
 * @tparam T type of virtual widget to create
 * @param element IUIAutomationElement* to get value from
 * @return virtual widget of type T with basic attributed populated
 */
template <typename T>
std::shared_ptr<T> CreateWidgetWithAttributes(IUIAutomationElement* element) {
  auto widget = std::make_shared<T>();
  vwidget_factory::PopulateSharedAttributes(widget, element);
  return widget;
}
}  // namespace vwidget_factory
