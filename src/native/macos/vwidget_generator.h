#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <unordered_set>
#include "vwidget/virtual_widget.h"
#include "vwidget/widgets/virtual_button_widget.h"
#include "vwidget/widgets/virtual_menu_item_widget.h"
#include "vwidget/widgets/virtual_text_widget.h"
#include "vwidget/widgets/virtual_text_field_widget.h"
#include "vwidget/widgets/virtual_menu_group_widget.h"
#include "vwidget/widgets/virtual_root_widget.h"
#include "vwidget/widgets/virtual_window_widget.h"


namespace VWidgetGenerator {
    /**
     * List of role id constants
     */
    inline constexpr std::string_view BUTTON_ROLE_ID = "AXButton";
    inline constexpr std::string_view CHECKBOX_ROLE_ID = "AXCheckBox";
    inline constexpr std::string_view RADIO_BUTTON_ROLE_ID = "AXRadioButton";
    inline constexpr std::string_view TEXT_FIELD_ROLE_ID = "AXTextField";
    inline constexpr std::string_view STATIC_TEXT_ROLE_ID = "AXStaticText";
    inline constexpr std::string_view COMBO_BOX_ROLE_ID = "AXComboBox";
    inline constexpr std::string_view MENU_BUTTON_ROLE_ID = "AXMenuButton";
    inline constexpr std::string_view MENU_BAR_ITEM_ROLE_ID = "AXMenuBarItem";
    inline constexpr std::string_view MENU_ROLE_ID = "AXMenu";
    inline constexpr std::string_view MENU_BAR_ROLE_ID = "AXMenuBar";
    inline constexpr std::string_view WINDOW_ROLE_ID = "AXWindow";
    inline constexpr std::string_view APPLICATION_ROLE_ID = "AXApplication";

    inline const std::unordered_map<std::string_view, std::function<std::shared_ptr<VirtualWidget>()>> ROLE_TO_VWIDGET_MAP = {
            {BUTTON_ROLE_ID,        []() { return std::make_shared<VirtualButtonWidget>(); }},
            {CHECKBOX_ROLE_ID,      []() { return std::make_shared<VirtualButtonWidget>(); }},
            {COMBO_BOX_ROLE_ID,     []() { return std::make_shared<VirtualButtonWidget>(); }},
            {RADIO_BUTTON_ROLE_ID,  []() { return std::make_shared<VirtualButtonWidget>(); }},
            {MENU_BUTTON_ROLE_ID,   []() { return std::make_shared<VirtualMenuItemWidget>(); }},
            {MENU_BAR_ITEM_ROLE_ID, []() { return std::make_shared<VirtualMenuItemWidget>(); }},
            {STATIC_TEXT_ROLE_ID,   []() { return std::make_shared<VirtualTextWidget>(); }},
            {TEXT_FIELD_ROLE_ID,    []() { return std::make_shared<VirtualTextFieldWidget>(); }},
            {MENU_BAR_ROLE_ID,      []() { return std::make_shared<VirtualMenuGroupWidget>(); }},
            {MENU_ROLE_ID,          []() { return std::make_shared<VirtualMenuGroupWidget>(); }},
            {APPLICATION_ROLE_ID,   []() { return std::make_shared<VirtualRootWidget>(); }},
            {WINDOW_ROLE_ID, []() { return std::make_shared<VirtualWindowWidget>(); }}
    };

    std::shared_ptr<VirtualRootWidget> generateVWidgetTree(AXUIElementRef rootElement);

    std::shared_ptr<VirtualWidget> getVWidget(AXUIElementRef element);
}
