#include "src/native/macos/vwidget_factory.h"
#include "src/native/macos/utils/cf_utils.h"
#include "include/vwidget/orientation.h"

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
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualTextInputWidget>(element);
  if (auto selected_text_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXSelectedTextAttribute)) {
    widget->SetSelectedText(selected_text_opt.value());
  }
  widget->SetIsTextArea(widget->GetNativeName() == "AXTextArea");

  // Overwrite the title attribute of a text input to be the user input content
  if (auto value_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXValueAttribute)) {
    widget->SetTitleText(value_opt.value());
  }

  return widget;
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
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualWindowWidget>(element);
  if (auto is_modal_opt = cf_utils::GetAttribute<bool>(element, kAXModalAttribute)) {
    widget->SetIsModal(is_modal_opt.value());
  }
  return widget;
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
  auto widget = vwidget_factory::CreateWidgetWithAttributes<VirtualProgressBarWidget>(element);
  if (auto orientation_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXOrientationAttribute)) {
    if (orientation_opt.value() == "AXVerticalOrientation") {
      widget->SetOrientation(Orientation::VERTICAL);
    } else {
      // it is possible that native orientation to be kAXUnknownOrientationValue, but we don't handle that
      // just defaulting to horizontal.
      widget->SetOrientation(Orientation::HORIZONTAL);
    }
  }
  return widget;
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
    widget->SetTitleText(title_opt.value());
  } else if (auto desc_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXDescriptionAttribute)) {
    widget->SetTitleText(desc_opt.value());
  }

  // Help text
  // This falls back to kAXRoleDescriptionAttribute when there is no kAXHelpAttribute
  if (auto help_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXHelpAttribute)) {
    widget->SetHelpText(help_opt.value());
  } else if (auto role_desc_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXRoleDescriptionAttribute)) {
    widget->SetHelpText(role_desc_opt.value());
  }

  // Native name (AXRole)
  if (auto native_name_opt = vwidget_factory::GetNonEmptyStringAttribute(element, kAXRoleAttribute)) {
    widget->SetNativeName(native_name_opt.value());
  }

  // Position
  if (auto position_opt = cf_utils::GetAttribute<CGPoint>(element, kAXPositionAttribute)) {
    widget->SetX(static_cast<int>(position_opt->x));
    widget->SetY(static_cast<int>(position_opt->y));
  }

  // Visibility and Dimension (Width and Height)
  if (auto dim_opt = cf_utils::GetAttribute<CGSize>(element, kAXSizeAttribute)) {
    auto width = static_cast<unsigned int>(dim_opt->width);
    auto height = static_cast<unsigned int>(dim_opt->height);
    widget->SetWidth(width);
    widget->SetHeight(height);

    bool parent_visibility = true;
    auto parent_widget = widget->GetParent();
    if (parent_widget) {
      parent_visibility = parent_widget->IsVisible();
    }

    widget->SetVisible(width != 0 && height != 0 && parent_visibility);
  }

  // Focused
  if (auto focused_opt = cf_utils::GetAttribute<bool>(element, kAXFocusedAttribute)) {
    widget->SetFocused(focused_opt.value());
  }
}
