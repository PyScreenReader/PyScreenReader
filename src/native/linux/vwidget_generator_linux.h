#pragma once

#include <atspi/atspi.h>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
// FIXME: (#43) uncomment the below line once mac refactor merges in
// #include "include/vwidget/widgets/virtual_group_widget.h"
#include "include/vwidget/widgets/virtual_menu_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"
#include "include/vwidget/widgets/virtual_scrollbar_widget.h"
#include "include/vwidget/widgets/virtual_spinner_widget.h"
#include "include/vwidget/widgets/virtual_slider_widget.h"
#include "include/vwidget/widgets/virtual_progress_bar_widget.h"

#include "src/native/linux/vwidget_factory_linux.h"

#define REGISTER_HANDLER(role_id, widget_type) \
  {role_id,                                    \
   [](AtspiAccessible *element) { return vwidget_factory::CreateWidget<widget_type>(element); }}

namespace vwidget_generator {

/**
 * Type of a native widget handler.
 */
using NativeWidgetHandler = std::function<std::shared_ptr<VirtualWidget>(AtspiAccessible *)>;

/**
 * Type of a handler map, which registers all the native maps to its corresponding WidgetHandler.
 */
using RoleHandlerMap = std::unordered_map<std::string, NativeWidgetHandler>;

/**
 * The following map is partially constructed from the below documentation:
 * https://docs.gtk.org/atspi2/enum.Role.html
*/
const RoleHandlerMap kRoleWidgetMap = {
  // Button roles
  REGISTER_HANDLER(Atspi.Role.PUSH_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.CHECK_BOX, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.COMBO_BOX, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.RADIO_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.TOGGLE_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.PAGE_TAB, VirtualButtonWidget),
  REGISTER_HANDLER(Atspi.Role.LINK, VirtualButtonWidget),

  // Text display roles
  REGISTER_HANDLER(Atspi.Role.TEXT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.LABEL, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.CAPTION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.HEADING, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DOCUMENT_TEXT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DOCUMENT_EMAIL, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DOCUMENT_WEB, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.COMMENT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.PARAGRAPH, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.BLOCK_QUOTE, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.HEADER, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.FOOTER, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.ACCELERATOR_LABEL, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.STATIC, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.MATH, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DEFINITION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.LOG, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.MARQUEE, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.TIMER, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.MATH_FRACTION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.MATH_ROOT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.SUBSCRIPT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.SUPERSCRIPT, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.FOOTNOTE, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.CONTENT_DELETION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.CONTENT_INSERTION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.MARK, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.SUGGESTION, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DESCRIPTION_TERM, VirtualTextWidget),
  REGISTER_HANDLER(Atspi.Role.DESCRIPTION_VALUE, VirtualTextWidget),
  
  // Text input roles
  REGISTER_HANDLER(Atspi.Role.PASSWORD_TEXT, VirtualTextInputWidget),
  REGISTER_HANDLER(Atspi.Role.DATE_EDITOR, VirtualTextInputWidget),
  REGISTER_HANDLER(Atspi.Role.EDITBAR, VirtualTextInputWidget),
  REGISTER_HANDLER(Atspi.Role.TERMINAL, VirtualTextInputWidget),
  REGISTER_HANDLER(Atspi.Role.ENTRY, VirtualTextInputWidget),

  // Menu system roles
  REGISTER_HANDLER(Atspi.Role.CHECK_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(Atspi.Role.RADIO_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(Atspi.Role.TEAR_OFF_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(Atspi.Role.POPUP_MENU, VirtualMenuWidget),
  REGISTER_HANDLER(Atspi.Role.MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(Atspi.Role.MENU, VirtualMenuWidget),
  REGISTER_HANDLER(Atspi.Role.MENU_BAR, VirtualMenuWidget),

  // Window/frame roles
  REGISTER_HANDLER(Atspi.Role.ALERT, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.DIALOG, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.WINDOW, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.APPLICATION, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.DESKTOP_FRAME, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.DOCUMENT_FRAME, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.INPUT_METHOD_WINDOW, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.NOTIFICATION, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.COLOR_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.FILE_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.FONT_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(Atspi.Role.FRAME, VirtualWindowWidget),

  // Grouping/container roles (commented until VirtualGroupWidget available)
  // REGISTER_HANDLER(Atspi.Role.CALENDAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.CANVAS, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.COLUMN_HEADER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DIRECTORY_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DRAWING_AREA, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.GLASS_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.GROUPING, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.INTERNAL_FRAME, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LAYERED_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.OPTION_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.PAGE_TAB_LIST, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.PANEL, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.ROOT_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.ROW_HEADER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SCROLL_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SPLIT_PANE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TABLE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TABLE_CELL, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TABLE_ROW, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TABLE_COLUMN_HEADER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TABLE_ROW_HEADER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TREE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TREE_ITEM, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TREE_TABLE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.VIEWPORT, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SECTION, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LANDMARK, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.ARTICLE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DESCRIPTION_LIST, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LIST, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LIST_ITEM, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DOCUMENT_PRESENTATION, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DOCUMENT_SPREADSHEET, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.EMBEDDED, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.FORM, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.IMAGE_MAP, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.INFO_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LEVEL_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TITLE_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.RATING, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.AUTOCOMPLETE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SCROLL_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SEPARATOR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SLIDER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.SPIN_BUTTON, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.STATUS_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TOOL_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.TOOL_TIP, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.PROGRESS_BAR, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.LIST_BOX, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.CHART, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.PAGE, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.DIAL, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.HTML_CONTAINER, VirtualGroupWidget),
  // REGISTER_HANDLER(Atspi.Role.RULER, VirtualGroupWidget),

  // Other interactive widgets
  REGISTER_HANDLER(Atspi.Role.SCROLL_BAR, VirtualScrollbarWidget),
  REGISTER_HANDLER(Atspi.Role.SLIDER, VirtualSliderWidget),
  REGISTER_HANDLER(Atspi.Role.SPIN_BUTTON, VirtualSpinnerWidget),
  REGISTER_HANDLER(Atspi.Role.PROGRESS_BAR, VirtualProgressBarWidget),

  // Special case roles
  REGISTER_HANDLER(Atspi.Role.ANIMATION, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.ARROW, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.DESKTOP_ICON, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.FILLER, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.ICON, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.IMAGE, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.REDUNDANT_OBJECT, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.EXTENDED, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.INVALID, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.LAST_DEFINED, VirtualUnknownWidget),
  REGISTER_HANDLER(Atspi.Role.UNKNOWN, VirtualUnknownWidget)};

std::shared_ptr<VirtualRootWidget>
GenerateVWidgetTree(AtspiAccessible *rootElement);

std::shared_ptr<VirtualWidget> MapToVWidget(AtspiAccessible *elem_atspi);
} // namespace vwidget_generator
