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
#include "include/vwidget/widgets/virtual_root_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
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
    {UIA_CalendarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_CheckBoxControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_ComboBoxControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_EditControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_HyperlinkControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_ImageControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_ListItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_ListControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_MenuControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuGroupWidget>(); }},
    {UIA_MenuBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuGroupWidget>(); }},
    {UIA_MenuItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualMenuItemWidget>(); }},
    {UIA_ProgressBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_RadioButtonControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualButtonWidget>(); }},
    {UIA_ScrollBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_SliderControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_SpinnerControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_StatusBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TabControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TabItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TextControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualTextWidget>(); }},
    {UIA_ToolBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_ToolTipControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TreeControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TreeItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_CustomControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_GroupControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_ThumbControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_DataGridControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_DataItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_DocumentControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_SplitButtonControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_WindowControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualWindowWidget>(); }},
    {UIA_PaneControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_HeaderControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_HeaderItemControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TableControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_TitleBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_SeparatorControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_SemanticZoomControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }},
    {UIA_AppBarControlTypeId, [](IUIAutomationElement* e){return std::make_shared<VirtualGroupWidget>(); }}
};
// clang-format on
// NOLINTEND(readability-identifier-length)

std::shared_ptr<VirtualRootWidget> GenerateVWidgetTree(IUIAutomationElement* root_element,
                                                       IUIAutomationTreeWalker* tree_walker);

std::shared_ptr<VirtualWidget> CreateVirtualWidget(IUIAutomationElement* element);
}  // namespace generator
