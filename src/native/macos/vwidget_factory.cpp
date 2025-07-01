#include "src/native/macos/vwidget_factory.h"
#include "src/native/macos/utils/cf_utils.h"

template <>
std::shared_ptr<VirtualButtonWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualButtonWidget>(element);
}

template <>
std::shared_ptr<VirtualTextWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualTextWidget>(element);
  if (auto value_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXValueAttribute)) {
    widget->SetTitleText(value_opt.value());
  }
  return widget;
}

template <>
std::shared_ptr<VirtualTextInputWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualTextInputWidget>(element);
}

template <>
std::shared_ptr<VirtualMenuWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuWidget>(element);
}

template <>
std::shared_ptr<VirtualMenuItemWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualMenuItemWidget>(element);
}

template <>
std::shared_ptr<VirtualWindowWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualWindowWidget>(element);
}

template <>
std::shared_ptr<VirtualGroupWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualGroupWidget>(element);
}

template <>
std::shared_ptr<VirtualUnknownWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualUnknownWidget>(element);
}

template <>
std::shared_ptr<VirtualScrollbarWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualScrollbarWidget>(element);
}

template <>
std::shared_ptr<VirtualSliderWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSliderWidget>(element);
}

template <>
std::shared_ptr<VirtualProgressBarWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualProgressBarWidget>(element);
}

template <>
std::shared_ptr<VirtualSpinnerWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return vwidget_factory::CreateWidgetWithAttributes<VirtualSpinnerWidget>(element);
}

std::optional<std::string> vwidget_factory::GetNonEmptyStringAttribute(AXUIElementRef element, CFStringRef attr) {
  if (auto str_opt = cf_utils::GetAttribute<std::string>(element, attr)) {
    if (!str_opt->empty()) return str_opt;
  }
  return std::nullopt;
}

void vwidget_factory::PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget, AXUIElementRef element) {
  if (!widget || !element) {
    return;
  }

  // Title
  if (auto title_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXTitleAttribute)) {
    widget->SetTitleText(*title_opt);
  } else if (auto desc_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXDescriptionAttribute)) {
    widget->SetTitleText(*desc_opt);
  }

  // Help text
  // This falls back to kAXRoleDescriptionAttribute when there is no kAXHelpAttribute
  if (auto help_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXHelpAttribute)) {
    widget->SetHelpText(*help_opt);
  } else if (auto role_desc_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXRoleDescriptionAttribute)) {
    widget->SetHelpText(*role_desc_opt);
  }

  // Native name (AXRole)
  if (auto native_name_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXRoleAttribute)) {
    widget->SetNativeName(*native_name_opt);
  }

  // Position
  if (auto position_opt = cf_utils::GetAttribute<CGPoint>(element, kAXPositionAttribute)) {
    widget->SetX(static_cast<int>(position_opt->x));
    widget->SetY(static_cast<int>(position_opt->y));
  }

  // Dimension (Width and Height)
  if (auto dim_opt = cf_utils::GetAttribute<CGSize>(element, kAXSizeAttribute)) {
    widget->SetWidth(static_cast<int>(dim_opt->width));
    widget->SetHeight(static_cast<int>(dim_opt->height));
  }

  // Visibility
  if (auto hidden_opt = cf_utils::GetAttribute<bool>(element, kAXHiddenAttribute)) {
    // kAXHiddenAttribute is true if hidden, so invert for IsVisible
    widget->SetVisible(!hidden_opt.value());
  }

  // Focused
  if (auto focused_opt = cf_utils::GetAttribute<bool>(element, kAXFocusedAttribute)) {
    widget->SetFocused(focused_opt.value());
  }
}
