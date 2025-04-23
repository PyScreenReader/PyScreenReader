#pragma once

#include <unordered_map>
#include <functional>
#include <windows.h>
#include <unordered_set>
#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_text_field_widget.h"
#include "include/vwidget/widgets/virtual_menu_group_widget.h"
#include "include/vwidget/widgets/virtual_root_widget.h"
#include <uiautomationclient.h>

namespace generator
{
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
        BUTTON_ROLE_ID,
        CHECKBOX_ROLE_ID,
        RADIO_BUTTON_ROLE_ID,
        TEXT_FIELD_ROLE_ID,
        STATIC_TEXT_ROLE_ID,
        COMBO_BOX_ROLE_ID,
        MENU_BUTTON_ROLE_ID,
        MENU_BAR_ITEM_ROLE_ID,
        MENU_BAR_ROLE_ID,
        WINDOW_ROLE_ID,
    };

    const std::unordered_map<std::string, std::function<std::shared_ptr<VirtualWidget>()>> ROLE_TO_VWIDGET_MAP = {
        {BUTTON_ROLE_ID, []() { return std::make_shared<VirtualButtonWidget>(); }},
        {CHECKBOX_ROLE_ID, []() { return std::make_shared<VirtualButtonWidget>(); }},
        {MENU_BUTTON_ROLE_ID, []() { return std::make_shared<VirtualMenuItemWidget>(); }},
        {MENU_BAR_ITEM_ROLE_ID, []() { return std::make_shared<VirtualMenuItemWidget>(); }},
        {COMBO_BOX_ROLE_ID, []() { return std::make_shared<VirtualButtonWidget>(); }},
        {RADIO_BUTTON_ROLE_ID, []() { return std::make_shared<VirtualButtonWidget>(); }},
        {STATIC_TEXT_ROLE_ID, []() { return std::make_shared<VirtualTextWidget>(); }},
        {TEXT_FIELD_ROLE_ID, []() { return std::make_shared<VirtualTextFieldWidget>(); }},
        {MENU_BAR_ROLE_ID, []() { return std::make_shared<VirtualMenuGroupWidget>(); }}
    };


    std::shared_ptr<VirtualRootWidget> GenerateVWidgetTree(IUIAutomationElement* root_element,
                                                           const std::shared_ptr<IUIAutomationTreeWalker>& tree_walker);

    std::shared_ptr<VirtualWidget> MakeVWidget(IUIAutomationElement* element);
}
