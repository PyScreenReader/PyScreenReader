#pragma once

#include <unordered_map>
#include <functional>
#include <windows.h>
#include <unordered_set>
#include "../../vwidget/virtual_widget.h"
#include "../../vwidget/widgets/virtual_button_widget.h"
#include "../../vwidget/widgets/virtual_menu_item_widget.h"
#include "../../vwidget/widgets/virtual_text_widget.h"
#include "../../vwidget/widgets/virtual_text_field_widget.h"
#include "../../vwidget/widgets/virtual_menu_group_widget.h"
#include "../../vwidget/widgets/virtual_root_widget.h"


namespace VWidgetGenerator {
    /**
     * List of role id constants
     */
    inline const std::string BUTTON_ROLE_ID = "kAXButtonRole";
    inline const std::string CHECKBOX_ROLE_ID = "kAXCheckBoxRole";
    inline const std::string RADIO_BUTTON_ROLE_ID = "kAXRadioButtonRole";
    inline const std::string TEXT_FIELD_ROLE_ID = "kAXTextFieldRole";
    inline const std::string STATIC_TEXT_ROLE_ID = "kAXStaticTextRole";
    inline const std::string COMBO_BOX_ROLE_ID = "kAXComboBoxRole";
    inline const std::string MENU_BUTTON_ROLE_ID = "kAXMenuButtonRole";
    inline const std::string MENU_BAR_ITEM_ROLE_ID = "kAXMenuBarItemRole";
    inline const std::string MENU_BAR_ROLE_ID = "kAXMenuBarRole";
    inline const std::string WINDOW_ROLE_ID = "kAXWindowRole";

    /**
     * A set of current supported roles
     */
    inline const std::unordered_set<std::string> SUPPORTED_ROLES = {
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

    inline const std::unordered_map<std::string, std::function<std::shared_ptr<VirtualWidget>()>> ROLE_TO_VWIDGET_MAP = {
            {BUTTON_ROLE_ID,       []() { return std::make_shared<VirtualButtonWidget>(); }},
            {CHECKBOX_ROLE_ID,     []() { return std::make_shared<VirtualButtonWidget>(); }},
            {MENU_BUTTON_ROLE_ID,  []() { return std::make_shared<VirtualMenuItemWidget>(); }},
            {MENU_BAR_ITEM_ROLE_ID,  []() { return std::make_shared<VirtualMenuItemWidget>(); }},
            {COMBO_BOX_ROLE_ID,    []() { return std::make_shared<VirtualButtonWidget>(); }},
            {RADIO_BUTTON_ROLE_ID, []() { return std::make_shared<VirtualButtonWidget>(); }},
            {STATIC_TEXT_ROLE_ID,  []() { return std::make_shared<VirtualTextWidget>(); }},
            {TEXT_FIELD_ROLE_ID,  []() { return std::make_shared<VirtualTextFieldWidget>(); }},
            {MENU_BAR_ROLE_ID, [](){ return std::make_shared<VirtualMenuGroupWidget>(); }}
    };


    std::shared_ptr<VirtualRootWidget> generateVWidgetTree(int rootElement);

    std::shared_ptr<VirtualWidget> getVWidget(int element);
}
