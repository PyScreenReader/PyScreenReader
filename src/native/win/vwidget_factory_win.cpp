#include "vwidget_factory_win.h"

template <>
std::shared_ptr<VirtualButtonWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualTextWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualTextInputWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualMenuWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualMenuItemWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualWindowWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualGroupWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualUnknownWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualScrollbarWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualSliderWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualProgressBarWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

template <>
std::shared_ptr<VirtualSpinnerWidget> vwidget_factory::CreateWidget(IUIAutomationElement* element);

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