#pragma once

#include <uiautomationclient.h>
#include <functional>
#include <unordered_map>
#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
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
#include "src/native/win/vwidget_factory_win.h"

#define REGISTER_HANDLER(role_id, widget_type)                   \
  {role_id, [](IUIAutomationElement* element) {                  \
     return vwidget_factory::CreateWidget<widget_type>(element); \
   }}

namespace vwidget_generator {

/**
 * Type of native widget handler.
 */
using NativeWidgetHandler = std::function<std::shared_ptr<VirtualWidget>(IUIAutomationElement*)>;

/**
 * Type of handler map, which registers all the native maps to its corresponding WidgetHandler.
 */
using RoleHandlerMap = std::unordered_map<CONTROLTYPEID, NativeWidgetHandler>;

/**
 * Mapping between native widgets to virtual widgets, effectively the Widget Factory
 *
 * The grouping has been defined by the required Providers implemented by each ControlTypeID.
 * Provider interfaces contain additional unique information which specify further functionality
 * for an IUIAutomationElement (e.g. ITextProvider confirms support for ITextProvider::GetSelection
 * which provides currently selected text by the user).
 */
const RoleHandlerMap kRoleWidgetMap = {
    // IExpandCollapseProvider OR (IInvokeProvider XOR IToggleProvider)
    REGISTER_HANDLER(UIA_ButtonControlTypeId, VirtualButtonWidget),
    // IToggleProvider
    REGISTER_HANDLER(UIA_CheckBoxControlTypeId, VirtualButtonWidget),
    // IExpandCollapseProvider
    REGISTER_HANDLER(UIA_ComboBoxControlTypeId, VirtualButtonWidget),
    // IInvokeProvider (IValueProvider OR Value)?
    REGISTER_HANDLER(UIA_HyperlinkControlTypeId, VirtualButtonWidget),
    // IExpandCollapseProvider AND IInvokeProvider
    REGISTER_HANDLER(UIA_SplitButtonControlTypeId, VirtualButtonWidget),
    // ISelectionItemProvider AND SelectionContainer
    REGISTER_HANDLER(UIA_RadioButtonControlTypeId, VirtualButtonWidget),

    // ITextProvider
    REGISTER_HANDLER(UIA_EditControlTypeId, VirtualTextInputWidget),
    // ITextProvider
    REGISTER_HANDLER(UIA_TextControlTypeId, VirtualTextWidget),
    // ITextProvider
    REGISTER_HANDLER(UIA_DocumentControlTypeId, VirtualTextWidget),
    // ITextProvider
    REGISTER_HANDLER(UIA_ToolTipControlTypeId, VirtualTextWidget),
    // Value
    REGISTER_HANDLER(UIA_ProgressBarControlTypeId, VirtualProgressBarWidget),

    // ISelectionProvider
    REGISTER_HANDLER(UIA_TabControlTypeId, VirtualMenuWidget),
    // ISelectionItemProvider
    REGISTER_HANDLER(UIA_TabItemControlTypeId, VirtualMenuItemWidget),

    // IExpandCollapseProvider AND SelectionContainer
    REGISTER_HANDLER(UIA_TreeItemControlTypeId, VirtualGroupWidget),
    // IExpandCollapseProvider?
    REGISTER_HANDLER(UIA_GroupControlTypeId, VirtualGroupWidget),
    // IGridProvider
    REGISTER_HANDLER(UIA_DataGridControlTypeId, VirtualGroupWidget),
    // IGridProvider AND ITableProvider
    REGISTER_HANDLER(UIA_TableControlTypeId, VirtualGroupWidget),

    // ITransformProvider AND IWindowProvider
    REGISTER_HANDLER(UIA_WindowControlTypeId, VirtualWindowWidget),

    // Misc. none or optional control patterns
    REGISTER_HANDLER(UIA_CalendarControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_ImageControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_ListItemControlTypeId, VirtualGroupWidget),
    REGISTER_HANDLER(UIA_ListControlTypeId, VirtualGroupWidget),
    REGISTER_HANDLER(UIA_MenuControlTypeId, VirtualMenuWidget),
    REGISTER_HANDLER(UIA_MenuBarControlTypeId, VirtualMenuWidget),
    REGISTER_HANDLER(UIA_MenuItemControlTypeId, VirtualMenuItemWidget),
    REGISTER_HANDLER(UIA_SliderControlTypeId, VirtualSliderWidget),
    REGISTER_HANDLER(UIA_SpinnerControlTypeId, VirtualSpinnerWidget),
    REGISTER_HANDLER(UIA_StatusBarControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_CustomControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_DataItemControlTypeId, VirtualGroupWidget),
    REGISTER_HANDLER(UIA_PaneControlTypeId, VirtualGroupWidget),
    REGISTER_HANDLER(UIA_HeaderControlTypeId, VirtualMenuWidget),
    REGISTER_HANDLER(UIA_HeaderItemControlTypeId, VirtualMenuItemWidget),
    REGISTER_HANDLER(UIA_TitleBarControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_SeparatorControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_SemanticZoomControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_AppBarControlTypeId, VirtualUnknownWidget),
    REGISTER_HANDLER(UIA_ToolBarControlTypeId, VirtualMenuWidget),
    REGISTER_HANDLER(UIA_TreeControlTypeId, VirtualGroupWidget),

    // Special cases:
    REGISTER_HANDLER(UIA_ScrollBarControlTypeId, VirtualScrollbarWidget),
    // ITransformProvider
    REGISTER_HANDLER(UIA_ThumbControlTypeId, VirtualUnknownWidget),

};

std::shared_ptr<VirtualWidget> GenerateVWidgetTree(IUIAutomationElement* root_element,
                                                   IUIAutomationTreeWalker* tree_walker);

std::shared_ptr<VirtualWidget> MapToVWidget(IUIAutomationElement* element);
}  // namespace vwidget_generator
