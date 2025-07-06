#include <cassert>

#include "src/native/linux/vwidget_factory_linux.h"
#include "src/native/linux/utils/atspi_utils.h"
#include "include/vwidget/orientation.h"

template <>
std::shared_ptr<VirtualButtonWidget> vwidget_factory::CreateWidget(AtspiAccessible *element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualButtonWidget>(element);
}

template <>
std::shared_ptr<VirtualTextWidget> vwidget_factory::CreateWidget(AtspiAccessible *element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualTextWidget>(element);
}

template <>
std::shared_ptr<VirtualTextInputWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualTextInputWidget>(element);
  return widget;
}

template <>
std::shared_ptr<VirtualMenuWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuWidget>(element);
}

template <>
std::shared_ptr<VirtualMenuItemWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuItemWidget>(element);
}

template <>
std::shared_ptr<VirtualWindowWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualWindowWidget>(element);
  return widget;
}

template <>
std::shared_ptr<VirtualGroupWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualGroupWidget>(element);
}

template <>
std::shared_ptr<VirtualUnknownWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualUnknownWidget>(element);
}

template <>
std::shared_ptr<VirtualScrollbarWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualScrollbarWidget>(element);
}

template <>
std::shared_ptr<VirtualSliderWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSliderWidget>(element);
}

template <>
std::shared_ptr<VirtualProgressBarWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualProgressBarWidget>(element);
  return widget;
}

template <>
std::shared_ptr<VirtualSpinnerWidget> vwidget_factory::CreateWidget(AtspiAccessible* element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSpinnerWidget>(element);
}

void vwidget_factory::PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget, AtspiAccessible* element) {
  assert (widget && element && "widget and element should not be null");

  // Title
  if (auto title_opt = atspi_utils::GetPrimaryText(element)) {
    widget->SetTitleText(title_opt.value());
  }

  // Help text
  if (auto help_opt = atspi_utils::GetHelpText(element)) {
    widget->SetHelpText(help_opt.value());
  }

  // Native name
  if (auto native_name_opt = atspi_utils::GetRoleName(element)) {
    widget->SetNativeName(native_name_opt.value());
  }

  bool is_visible = atspi_utils::GetVisibility(element);
  widget->SetVisible(is_visible);

  // Position and dimension values
  if (is_visible) {
    // Position value is only meaningful only when the component is visible
    // https://docs.gtk.org/atspi2/method.Component.get_position.html
    if (auto position_opt = atspi_utils::GetPosition(element)) {
      widget->SetX(static_cast<int>(position_opt.value()->x));
      widget->SetY(static_cast<int>(position_opt.value()->y));
      free(position_opt.value());
    }

    // Dimension value is only meaningful only when the component is visible
    // https://docs.gtk.org/atspi2/method.Component.get_size.html
    if (auto dim_opt = atspi_utils::GetDimension(element)) {
      auto width = static_cast<unsigned int>(dim_opt.value()->x);
      auto height = static_cast<unsigned int>(dim_opt.value()->y);
      widget->SetWidth(width);
      widget->SetHeight(height);
      free(dim_opt.value());
    }
  }
  //TODO: Focused
}

