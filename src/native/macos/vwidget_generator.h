#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
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
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"

namespace generator {
    /**
     * List of role id constants
     *
     * These constant strings are copied from `AXRoleConstants.h`,
     * for simplicity and optimization purposes, we copied these values instead of referencing them.
     */
    // Button-like widgets
    inline constexpr std::string_view BUTTON_ROLE_ID = "AXButton";
    inline constexpr std::string_view CHECKBOX_ROLE_ID = "AXCheckBox";
    inline constexpr std::string_view COMBO_BOX_ROLE_ID = "AXComboBox";
    inline constexpr std::string_view RADIO_BUTTON_ROLE_ID = "AXRadioButton";
    inline constexpr std::string_view POP_UP_BUTTON_ROLE_ID = "AXPopUpButton";

    // Text-like widgets
    inline constexpr std::string_view TEXT_FIELD_ROLE_ID = "AXTextField";
    inline constexpr std::string_view TEXT_AREA_ROLE_ID = "AXTextArea";
    inline constexpr std::string_view STATIC_TEXT_ROLE_ID = "AXStaticText";
    inline constexpr std::string_view HEADING_ROLE_ID = "AXHeading";

    // Menu-related widgets
    inline constexpr std::string_view MENU_BUTTON_ROLE_ID = "AXMenuButton";
    inline constexpr std::string_view MENU_BAR_ITEM_ROLE_ID = "AXMenuBarItem";
    inline constexpr std::string_view MENU_ROLE_ID = "AXMenu";
    inline constexpr std::string_view MENU_BAR_ROLE_ID = "AXMenuBar";

    // Window-related widgets
    inline constexpr std::string_view WINDOW_ROLE_ID = "AXWindow";
    inline constexpr std::string_view APPLICATION_ROLE_ID = "AXApplication";

    // Grouping-related widgets
    inline constexpr std::string_view ROW_ROLE_ID = "AXRow";
    inline constexpr std::string_view COLUMN_ROLE_ID = "AXColumn";
    inline constexpr std::string_view LIST_ROLE_ID = "AXList";
    inline constexpr std::string_view GROUP_ROLE_ID = "AXGroup";
    inline constexpr std::string_view OUTLINE_ROLE_ID = "AXOutline";
    inline constexpr std::string_view CELL_ROLE_ID = "AXCell";
    inline constexpr std::string_view SCROLL_AREA_ROLE_ID = "AXScrollArea";

    // Unknown widgets
    inline constexpr std::string_view UNKNOWN_ROLE_ID = "AXUnknown";

    std::shared_ptr<VirtualWidget> HandleButtonLiked(AXUIElementRef element);
    std::shared_ptr<VirtualWidget> HandleUnknown(AXUIElementRef element);
    std::shared_ptr<VirtualWidget> HandleStaticText(AXUIElementRef element);

    inline const std::unordered_map<std::string_view, std::function<std::shared_ptr<VirtualWidget>(AXUIElementRef)>> ROLE_TO_VWIDGET_MAP = {
            {BUTTON_ROLE_ID,        [](AXUIElementRef element) { return HandleButtonLiked(element); }},
            {CHECKBOX_ROLE_ID,      [](AXUIElementRef element) { return std::make_shared<VirtualButtonWidget>(); }},
            {COMBO_BOX_ROLE_ID,     [](AXUIElementRef element) { return std::make_shared<VirtualButtonWidget>(); }},
            {RADIO_BUTTON_ROLE_ID,  [](AXUIElementRef element) { return std::make_shared<VirtualButtonWidget>(); }},
            {POP_UP_BUTTON_ROLE_ID,  [](AXUIElementRef element) { return std::make_shared<VirtualButtonWidget>(); }},

            {STATIC_TEXT_ROLE_ID,   [](AXUIElementRef element) { return HandleStaticText(element); }},
            {HEADING_ROLE_ID,   [](AXUIElementRef element) { return HandleStaticText(element); }},
            {TEXT_FIELD_ROLE_ID,    [](AXUIElementRef element) { return std::make_shared<VirtualTextFieldWidget>(); }},
            {TEXT_AREA_ROLE_ID,    [](AXUIElementRef element) { return std::make_shared<VirtualTextFieldWidget>(); }},

            {MENU_BAR_ROLE_ID,      [](AXUIElementRef element) { return std::make_shared<VirtualMenuGroupWidget>(); }},
            {MENU_ROLE_ID,          [](AXUIElementRef element) { return std::make_shared<VirtualMenuGroupWidget>(); }},
            {MENU_BUTTON_ROLE_ID,   [](AXUIElementRef element) { return std::make_shared<VirtualMenuItemWidget>(); }},
            {MENU_BAR_ITEM_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualMenuItemWidget>(); }},

            {WINDOW_ROLE_ID,       [](AXUIElementRef element) { return std::make_shared<VirtualWindowWidget>(); }},
            {APPLICATION_ROLE_ID,   [](AXUIElementRef element) { return std::make_shared<VirtualRootWidget>(); }},

            {ROW_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {COLUMN_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {LIST_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {GROUP_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {OUTLINE_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {CELL_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},
            {SCROLL_AREA_ROLE_ID, [](AXUIElementRef element) { return std::make_shared<VirtualGroupWidget>(); }},

            {UNKNOWN_ROLE_ID, [](AXUIElementRef element) { return HandleUnknown(element); }}
    };

    std::shared_ptr<VirtualRootWidget> GenerateVWidgetTree(AXUIElementRef rootElement);

    std::shared_ptr<VirtualWidget> GetVWidget(AXUIElementRef element);
}
