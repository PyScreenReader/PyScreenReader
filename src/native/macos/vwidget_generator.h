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
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"
#include "include/vwidget/widgets/virtual_group_widget.h"

#include "src/native/macos/vwidget_factory.h"

#define REGISTER_HANDLER(role_id, widget_type) \
  {role_id,                                    \
   [](AXUIElementRef element) { return vwidget_factory::CreateWidget<widget_type>(element); }}

namespace vwidget_generator {
/**
 * List of role id constants
 *
 * These constant strings are copied from `AXRoleConstants.h`,
 * for simplicity and optimization purposes, we copied these values instead of directly using
 * CFStringRef.
 */
// Button-like widgets
const std::string kButtonRoleId = "AXButton";
const std::string kCheckBoxRoleId = "AXCheckBox";
const std::string kComboBoxRoleId = "AXComboBox";
const std::string kRadioButtonRoleId = "AXRadioButton";
const std::string kPopUpButtonRoleId = "AXPopUpButton";

// Text-like widgets
const std::string kTextFieldRoleId = "AXTextField";
const std::string kTextAreaRoleId = "AXTextArea";
const std::string kStaticTextRoleId = "AXStaticText";
const std::string kHeadingRoleId = "AXHeading";

// Menu-related widgets
const std::string kMenuButtonRoleId = "AXMenuButton";
const std::string kMenuBarItemRoleId = "AXMenuBarItem";
const std::string kMenuRoleId = "AXMenu";
const std::string kMenuBarRoleId = "AXMenuBar";

// Window-related widgets
const std::string kWindowRoleId = "AXWindow";
const std::string kApplicationRoleId = "AXApplication";

// Grouping-related widgets
const std::string kRowRoleId = "AXRow";
const std::string kColumnRoleId = "AXColumn";
const std::string kListRoleId = "AXList";
const std::string kGroupRoleId = "AXGroup";
const std::string kOutlineRoleId = "AXOutline";
const std::string kCellRoleId = "AXCell";
const std::string kScrollAreaRoleId = "AXScrollArea";
const std::string kTableRoleId = "AXTable";

// Unknown widgets
const std::string kUnknownRoleId = "AXUnknown";

/**
 * Type of a native widget handler.
 */
using NativeWidgetHandler = std::function<std::shared_ptr<VirtualWidget>(AXUIElementRef)>;

/**
 * Type of a handler map, which registers all the native maps to its corresponding WidgetHandler.
 */
using RoleHandlerMap = std::unordered_map<std::string, NativeWidgetHandler>;

/**
 * Mapping between native widgets to virtual widgets
 */
inline RoleHandlerMap kRoleWidgetMap = {REGISTER_HANDLER(kButtonRoleId, VirtualButtonWidget),
                                        REGISTER_HANDLER(kCheckBoxRoleId, VirtualButtonWidget),
                                        REGISTER_HANDLER(kComboBoxRoleId, VirtualButtonWidget),
                                        REGISTER_HANDLER(kRadioButtonRoleId, VirtualButtonWidget),
                                        REGISTER_HANDLER(kPopUpButtonRoleId, VirtualButtonWidget),

                                        REGISTER_HANDLER(kStaticTextRoleId, VirtualTextWidget),

                                        REGISTER_HANDLER(kHeadingRoleId, VirtualTextInputWidget),
                                        REGISTER_HANDLER(kTextFieldRoleId, VirtualTextInputWidget),
                                        REGISTER_HANDLER(kTextAreaRoleId, VirtualTextInputWidget),

                                        REGISTER_HANDLER(kMenuBarRoleId, VirtualMenuWidget),
                                        REGISTER_HANDLER(kMenuRoleId, VirtualMenuWidget),
                                        REGISTER_HANDLER(kMenuButtonRoleId, VirtualMenuItemWidget),
                                        REGISTER_HANDLER(kMenuBarItemRoleId, VirtualMenuItemWidget),

                                        REGISTER_HANDLER(kWindowRoleId, VirtualWindowWidget),
                                        REGISTER_HANDLER(kApplicationRoleId, VirtualWindowWidget),

                                        REGISTER_HANDLER(kRowRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kColumnRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kListRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kGroupRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kOutlineRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kCellRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kScrollAreaRoleId, VirtualGroupWidget),
                                        REGISTER_HANDLER(kTableRoleId, VirtualGroupWidget),

                                        REGISTER_HANDLER(kUnknownRoleId, VirtualUnknownWidget)};

/**
 * Translates a native macOS widget tree into a virtual widget tree.
 *
 * @param rootElement The root AXUIElementRef of the native widget tree.
 * @return A shared pointer to the root of the generated virtual widget tree.
 */
std::shared_ptr<VirtualWidget> GenerateVWidgetTree(AXUIElementRef root_element);

std::shared_ptr<VirtualWidget> MapToVWidget(AXUIElementRef element);
}  // namespace vwidget_generator
