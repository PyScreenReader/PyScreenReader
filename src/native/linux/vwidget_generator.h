#pragma once
#include <functional>
#include <string_view>

#include <memory>
#include <unordered_map>

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_group_widget.h"
#include "include/vwidget/widgets/virtual_menu_group_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_root_widget.h"
#include "include/vwidget/widgets/virtual_text_field_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"

namespace generator {

// button
const std::string_view BUTTON_ROLE_ID = "button";
const std::string_view PUSH_BUTTON_ROLE_ID = "push button";
const std::string_view CHECK_BOX_ROLE_ID = "check box";
const std::string_view COMBO_BOX_ROLE_ID = "combo box";
const std::string_view RADIO_BUTTON_ROLE_ID = "radio button";

// text
const std::string_view ENTRY_ROLE_ID = "entry";
const std::string_view TEXT_ROLE_ID = "text";
const std::string_view LABEL_ROLE_ID = "label";
const std::string_view HEADING_ROLE_ID = "heading";

// menu
const std::string_view PUSH_BUTTON_MENU_ROLE_ID = "push button menu";
const std::string_view MENU_ITEM_ROLE_ID = "menu item";
const std::string_view MENU_ROLE_ID = "menu";
const std::string_view MENU_BAR_ROLE_ID = "menu bar";

// window
const std::string_view FRAME_ROLE_ID = "frame";
const std::string_view APPLICATION_ROLE_ID = "application";

// grouping
const std::string_view TABLE_ROW_ROLE_ID = "table row";
const std::string_view TABLE_COLUMN_HEADER_ROLE_ID = "table column header";
const std::string_view LIST_ROLE_ID = "list";
const std::string_view GROUPING_ROLE_ID = "grouping";
const std::string_view TREE_ROLE_ID = "tree";
const std::string_view TABLE_CELL_ROLE_ID = "table cell";
const std::string_view SCROLL_PANE_ROLE_ID = "scroll pane";

// unknown
const std::string_view UNKNOWN_ROLE_ID = "unknown";

const std::unordered_map<
    std::string_view, std::function<std::shared_ptr<VirtualWidget>(AtspiRole)>>
    ROLE_TO_VWIDGET_MAP = {
        {BUTTON_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualButtonWidget>(); }},
        {PUSH_BUTTON_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualButtonWidget>(); }},
        {CHECK_BOX_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualButtonWidget>(); }},
        {COMBO_BOX_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualButtonWidget>(); }},
        {RADIO_BUTTON_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualButtonWidget>(); }},
        {ENTRY_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualTextFieldWidget>();
         }},
        {TEXT_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualTextFieldWidget>();
         }},
        {LABEL_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualTextFieldWidget>();
         }},
        {HEADING_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualTextFieldWidget>();
         }},
        {PUSH_BUTTON_MENU_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualMenuItemWidget>(); }},
        {MENU_ITEM_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualMenuItemWidget>(); }},
        {MENU_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualMenuGroupWidget>();
         }},
        {MENU_BAR_ROLE_ID,
         [](AtspiRole e) {
           return std::make_shared<VirtualMenuGroupWidget>();
         }},
        {FRAME_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualWindowWidget>(); }},
        {APPLICATION_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualRootWidget>(); }},
        {TABLE_ROW_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {TABLE_COLUMN_HEADER_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {LIST_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {GROUPING_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {TREE_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {TABLE_CELL_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {SCROLL_PANE_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualGroupWidget>(); }},
        {UNKNOWN_ROLE_ID,
         [](AtspiRole e) { return std::make_shared<VirtualUnknownWidget>(); }}};

std::shared_ptr<VirtualRootWidget> generateVWidgetTree();
std::shared_ptr<VirtualRootWidget> getVWidget();

} // namespace generator