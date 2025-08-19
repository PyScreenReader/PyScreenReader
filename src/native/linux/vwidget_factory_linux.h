#pragma once

#include <atspi/atspi.h>
#include <optional>

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

namespace vwidget_factory {
template <typename T>
std::shared_ptr<T> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualButtonWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualTextWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualTextInputWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualMenuWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualMenuItemWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualWindowWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualGroupWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualUnknownWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualScrollbarWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualSliderWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualProgressBarWidget> CreateWidget(AtspiAccessible* element);

template <>
std::shared_ptr<VirtualSpinnerWidget> CreateWidget(AtspiAccessible* element);

/**
 * Populate shared attributes across all the virtual widgets.
 * These shared attributes (e.g. title, dimensions) are defined in @see virtual_widget.h,
 * which is the parent class of all the derived virtual widgets.
 *
 * These populated values might be overwritten later in the handlers of each specific widgets.
 *
 * @param widget any type of virtual widget
 * @param element native AtspiAccessible to copy the values from
 * @note this function modifies the param widget
 */
void PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget, AtspiAccessible* element);

/**
 * Create virtual widget corresponds to the given AtspiAccessible
 * with basic non-specific attributes populated.
 *
 * @tparam T type of virtual widget to create
 * @param element AtspiAccessible to get value from
 * @return virtual widget of type T with basic attributed populated
 */
template <typename T>
std::shared_ptr<T> CreateWidgetWithAttributes(AtspiAccessible* element) {
  auto widget = std::make_shared<T>();
  vwidget_factory::PopulateSharedAttributes(widget, element);
  return widget;
}
}  // namespace vwidget_factory
