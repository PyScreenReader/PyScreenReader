#pragma once

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

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>

namespace vwidget_factory {
template <typename T>
std::shared_ptr<T> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualButtonWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualTextWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualTextInputWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualMenuWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualMenuItemWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualWindowWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualGroupWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualUnknownWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualScrollbarWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualSliderWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualProgressBarWidget> CreateWidget(AXUIElementRef element);

template <>
std::shared_ptr<VirtualSpinnerWidget> CreateWidget(AXUIElementRef element);

/**
 * Get string attribute values from AXUIElement.
 * If the string attribute is ""(empty string), this function
 * will return std::nullopt
 *
 * @param element AXUIElement to get the value from
 * @param attr attribute name
 * @return std::nullopt if fails to get attribute or the value is "", otherwise the string value
 */
std::optional<std::string> GetNonEmptyStringAttribute(AXUIElementRef element, CFStringRef attr);

/**
 * Populate shared attributes across all the virtual widgets.
 * These shared attributes (e.g. title, dimensions) are defined in @see virtual_widget.h,
 * which is the parent class of all the derived virtual widgets.
 *
 * These populated values might be overwritten later in the handlers of each specific widgets.
 *
 * @param widget any type of virtual widget
 * @param element native AXUIElementRef to copy the values from
 * @note this function modifies the param widget
 */
void PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget, AXUIElementRef element);

/**
 * Create virtual widget corresponds to the given AXUIElementRef
 * with basic non-specific attributes populated.
 *
 * @tparam T type of virtual widget to create
 * @param element AXUIElementRef to get value from
 * @return virtual widget of type T with basic attributed populated
 */
template <typename T>
std::shared_ptr<T> CreateWidgetWithAttributes(AXUIElementRef element) {
  auto widget = std::make_shared<T>();
  vwidget_factory::PopulateSharedAttributes(widget, element);
  return widget;
}
}  // namespace vwidget_factory
