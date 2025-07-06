#pragma once

#include <atspi/atspi.h>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_group_widget.h"
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
using NativeWidgetHandler = std::function<std::shared_ptr<VirtualWidget>(AtspiAccessible*)>;

/**
 * Type of a handler map, which registers all the native maps to its corresponding WidgetHandler.
 */
using RoleHandlerMap = std::unordered_map<AtspiRole, NativeWidgetHandler>;

/**
 * The following map is partially constructed from the below documentation:
 * https://docs.gtk.org/atspi2/enum.Role.html
*/
const RoleHandlerMap kRoleWidgetMap = {
  // Button roles
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PUSH_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CHECK_BOX, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_COMBO_BOX, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_RADIO_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TOGGLE_BUTTON, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PAGE_TAB, VirtualButtonWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LINK, VirtualButtonWidget),

  // Text display roles
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TEXT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LABEL, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CAPTION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_HEADING, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_TEXT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_EMAIL, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_WEB, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_COMMENT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PARAGRAPH, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_BLOCK_QUOTE, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_HEADER, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FOOTER, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ACCELERATOR_LABEL, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_STATIC, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MATH, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DEFINITION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LOG, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MARQUEE, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TIMER, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MATH_FRACTION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MATH_ROOT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SUBSCRIPT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SUPERSCRIPT, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FOOTNOTE, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CONTENT_DELETION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CONTENT_INSERTION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MARK, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SUGGESTION, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DESCRIPTION_TERM, VirtualTextWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DESCRIPTION_VALUE, VirtualTextWidget),

  // Text input roles
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PASSWORD_TEXT, VirtualTextInputWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DATE_EDITOR, VirtualTextInputWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_EDITBAR, VirtualTextInputWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TERMINAL, VirtualTextInputWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ENTRY, VirtualTextInputWidget),

  // Menu system roles
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CHECK_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_RADIO_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_POPUP_MENU, VirtualMenuWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MENU_ITEM, VirtualMenuItemWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MENU, VirtualMenuWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_MENU_BAR, VirtualMenuWidget),

  // Window/frame roles
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ALERT, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DIALOG, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_WINDOW, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_APPLICATION, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DESKTOP_FRAME, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_FRAME, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_INPUT_METHOD_WINDOW, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_NOTIFICATION, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_COLOR_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FILE_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FONT_CHOOSER, VirtualWindowWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FRAME, VirtualWindowWidget),

  // Grouping/container roles (commented until VirtualGroupWidget available)
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CALENDAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CANVAS, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_COLUMN_HEADER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DIRECTORY_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DRAWING_AREA, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_GLASS_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_GROUPING, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_INTERNAL_FRAME, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LAYERED_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_OPTION_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PAGE_TAB_LIST, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PANEL, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ROOT_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ROW_HEADER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SCROLL_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SPLIT_PANE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TABLE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TABLE_CELL, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TABLE_ROW, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TABLE_COLUMN_HEADER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TABLE_ROW_HEADER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TREE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TREE_ITEM, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TREE_TABLE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_VIEWPORT, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SECTION, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LANDMARK, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ARTICLE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DESCRIPTION_LIST, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LIST, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LIST_ITEM, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_PRESENTATION, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DOCUMENT_SPREADSHEET, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_EMBEDDED, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FORM, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_IMAGE_MAP, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_INFO_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LEVEL_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TITLE_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_RATING, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_AUTOCOMPLETE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SCROLL_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SEPARATOR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SLIDER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SPIN_BUTTON, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_STATUS_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TOOL_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_TOOL_TIP, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PROGRESS_BAR, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LIST_BOX, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_CHART, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PAGE, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DIAL, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_HTML_CONTAINER, VirtualGroupWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_RULER, VirtualGroupWidget),

  // Other interactive widgets
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SCROLL_BAR, VirtualScrollbarWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SLIDER, VirtualSliderWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_SPIN_BUTTON, VirtualSpinnerWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_PROGRESS_BAR, VirtualProgressBarWidget),

  // Special case role
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ANIMATION, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ARROW, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_DESKTOP_ICON, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_FILLER, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_ICON, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_IMAGE, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_REDUNDANT_OBJECT, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_EXTENDED, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_INVALID, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_LAST_DEFINED, VirtualUnknownWidget),
  REGISTER_HANDLER(AtspiRole::ATSPI_ROLE_UNKNOWN, VirtualUnknownWidget)};

std::shared_ptr<VirtualWidget>
GenerateVWidgetTree(AtspiAccessible *root_element);

std::shared_ptr<VirtualWidget> MapToVWidget(AtspiAccessible *elem_atspi);
} // namespace vwidget_generator
