#pragma once

#include <uiautomationclient.h>
#include <windows.h>
#include <functional>
#include <unordered_map>
#include <unordered_set>
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

namespace generator {
/**
 * List of role id constants
 */
const std::string BUTTON_ROLE_ID = "kAXButtonRole";
const std::string CHECKBOX_ROLE_ID = "kAXCheckBoxRole";
const std::string RADIO_BUTTON_ROLE_ID = "kAXRadioButtonRole";
const std::string TEXT_FIELD_ROLE_ID = "kAXTextFieldRole";
const std::string STATIC_TEXT_ROLE_ID = "kAXStaticTextRole";
const std::string COMBO_BOX_ROLE_ID = "kAXComboBoxRole";
const std::string MENU_BUTTON_ROLE_ID = "kAXMenuButtonRole";
const std::string MENU_BAR_ITEM_ROLE_ID = "kAXMenuBarItemRole";
const std::string MENU_BAR_ROLE_ID = "kAXMenuBarRole";
const std::string WINDOW_ROLE_ID = "kAXWindowRole";

/**
 * A set of current supported roles
 */
const std::unordered_set<std::string> SUPPORTED_ROLES = {
    BUTTON_ROLE_ID,      CHECKBOX_ROLE_ID,  RADIO_BUTTON_ROLE_ID, TEXT_FIELD_ROLE_ID,
    STATIC_TEXT_ROLE_ID, COMBO_BOX_ROLE_ID, MENU_BUTTON_ROLE_ID,  MENU_BAR_ITEM_ROLE_ID,
    MENU_BAR_ROLE_ID,    WINDOW_ROLE_ID,
};

// NOLINTBEGIN(readability-identifier-length)
// clang-format off
inline const std::unordered_map<CONTROLTYPEID, std::function<std::shared_ptr<VirtualWidget>(IUIAutomationElement*)>> VIRTUAL_WIDGET_FACTORY = {
    {UIA_ButtonControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_CalendarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_CheckBoxControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_ComboBoxControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_EditControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_HyperlinkControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualTextWidget>(); }},
    {UIA_ImageControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_ListItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_ListControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_MenuControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuWidget>(); }},
    {UIA_MenuBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuWidget>(); }},
    {UIA_MenuItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuItemWidget>(); }},
    {UIA_ProgressBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualProgressBarWidget>(); }},
    {UIA_RadioButtonControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_ScrollBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualScrollbarWidget>(); }},
    {UIA_SliderControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualSliderWidget>(); }},
    {UIA_SpinnerControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualSpinnerWidget>(); }},
    {UIA_StatusBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualProgressBarWidget>(); }},
    {UIA_TabControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TabItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TextControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualTextWidget>(); }},
    {UIA_ToolBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_ToolTipControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TreeControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TreeItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_CustomControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_GroupControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_ThumbControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_DataGridControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_DataItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_DocumentControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_SplitButtonControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_WindowControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualWindowWidget>(); }},
    {UIA_PaneControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_HeaderControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_HeaderItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TableControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_TitleBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualTextWidget>(); }},
    {UIA_SeparatorControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_SemanticZoomControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }},
    {UIA_AppBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualUnknownWidget>(); }}
};
// clang-format on
// NOLINTEND(readability-identifier-length)

std::shared_ptr<VirtualWidget> GenerateVWidgetTree(IUIAutomationElement* root_element,
                                                       IUIAutomationTreeWalker* tree_walker);

std::shared_ptr<VirtualWidget> CreateVirtualWidget(IUIAutomationElement* element);
}  // namespace generator
