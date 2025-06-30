#include "src/native/macos/vwidget_factory.h"

template <>
std::shared_ptr<VirtualButtonWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualButtonWidget>();
}

template <>
std::shared_ptr<VirtualTextWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualTextWidget>();
}

template <>
std::shared_ptr<VirtualTextInputWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualTextInputWidget>();
}

template <>
std::shared_ptr<VirtualMenuWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualMenuWidget>();
}

template <>
std::shared_ptr<VirtualMenuItemWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualMenuItemWidget>();
}

template <>
std::shared_ptr<VirtualWindowWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualWindowWidget>();
}

template <>
std::shared_ptr<VirtualGroupWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualGroupWidget>();
}

template <>
std::shared_ptr<VirtualUnknownWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualUnknownWidget>();
}

template <>
std::shared_ptr<VirtualScrollbarWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualScrollbarWidget>();
}

template <>
std::shared_ptr<VirtualSliderWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualSliderWidget>();
}

template <>
std::shared_ptr<VirtualProgressBarWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualProgressBarWidget>();
}

template <>
std::shared_ptr<VirtualSpinnerWidget> vwidget_factory::CreateWidget(AXUIElementRef element) {
  return std::make_shared<VirtualSpinnerWidget>();
}

void vwidget_factory::PopulateSharedAttributes(std::shared_ptr<VirtualWidget> widget) {

}
