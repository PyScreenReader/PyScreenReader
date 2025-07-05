#pragma once

#include <optional>
#include <string>
#include <atspi/atspi.h>

namespace atspi_utils {
/**
 * Get displayed text from native widgets which implement Text Interface.
 * 
 * @param element native atspi widget
 * @return optional title extracted from the widget
 * @note More about Text Interface: https://docs.gtk.org/atspi2/iface.Text.html
 */
std::optional<std::string> get_title_text(AtspiAccessible *element);


/**
 * Get help text from native widget.
 *
 * @param element native atspi widget
 * @return optional help text extracted from the widget
 */
std::optional<std::string> get_help_text(AtspiAccessible *element);


/**
 * Get role name from native widget.
 *
 * @param element native atspi widget
 * @return optional role name extracted from the widget
 */
std::optional<std::string> get_role_name(AtspiAccessible *element);


/**
 * Determines if the native element is visible from UI.
 *
 * @param element native atspi widget
 * @return true if the native widget is visible on UI
 */
bool get_visibility(AtspiAccessible *element);


/**
 * Get position information of the native element.
 *
 * @param element native atspi widget
 * @return optional position information
 * @note the caller should take ownership of the returned object, thus, should
 * be responsible to release the object
 */
std::optional<AtspiPoint*> get_position(AtspiAccessible *element);


/**
 * Get dimension information of the native element.
 *
 * @param element native atspi widget
 * @return optional dimension information
 * @note the caller should take ownership of the returned object, thus, should
 * be responsible to release the object
 */
std::optional<AtspiPoint*> get_dimension(AtspiAccessible *element);


/**
  * Convert glib string representation to std::string and free the original.
  *
  * @param text glib string representation
  * @return copied std::string
  * @note adjusted from https://github.com/mysql/mysql-workbench/blob/418f54b81440b974dba1ddc4a923334e0759fac5/tools/mga/src/aal/linux/accessible.cpp#L112
*/
std::string convert_string_and_free(gchar *text);
} // namespace atspi_utils

