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
std::optional<std::string> GetPrimaryText(AtspiAccessible *element);


/**
 * Get help text from native widget.
 *
 * @param element native atspi widget
 * @return optional help text extracted from the widget
 */
std::optional<std::string> GetHelpText(AtspiAccessible *element);


/**
 * Get the selected text in a native widget.
 *
 * @param element native atspi widget
 * @return optional user selected string value
 */
std::optional<std::string> GetSelectedText(AtspiAccessible *element);


/**
 * Get the numeric value represented by the native widget.
 * For example, 100% in a progress bar, etc.
 *
 * @param element native atspi widget
 * @return optional value
 */
std::optional<double> GetNumericValue(AtspiAccessible *element);

/**
 * Get AtspiRole from native widget.
 *
 * @param element native atspi widget
 * @return optional AtspiRole extracted from the widget
 * @note About AtspiRole: https://docs.gtk.org/atspi2/enum.Role.html
 */
std::optional<AtspiRole> GetRole(AtspiAccessible *element);


/**
 * Get role name from native widget.
 *
 * @param element native atspi widget
 * @return optional role name extracted from the widget
 */
std::optional<std::string> GetRoleName(AtspiAccessible *element);


/**
 * Determines if the native element is visible from UI.
 *
 * @param element native atspi widget
 * @return true if the native widget is visible on UI
 */
bool GetVisibility(AtspiAccessible *element);


/**
 * Get position information of the native element.
 *
 * @param element native atspi widget
 * @return optional position information
 * @note the caller should take ownership of the returned object, thus, should
 * be responsible to release the object
 */
std::optional<AtspiPoint*> GetPosition(AtspiAccessible *element);


/**
 * Get dimension information of the native element.
 *
 * @param element native atspi widget
 * @return optional dimension information
 * @note the caller should take ownership of the returned object, thus, should
 * be responsible to release the object
 */
std::optional<AtspiPoint*> GetDimension(AtspiAccessible *element);


/**
 * Get number of children belong to the given native widget.
 *
 * @param element native atspi widget
 * @return optional number of children
 */
std::optional<unsigned int> GetChildrenCount(AtspiAccessible *element);


/**
 * Get the child natearve widget of the given widget at the give index.
 *
 * @param element native widget to get the child from
 * @param child_index index of the child
 * @return optional widget object
 * @note the caller will take the ownership of the returned object
 */
std::optional<AtspiAccessible*> GetChildAtIndex(AtspiAccessible *element, unsigned int child_index);


/**
  * Convert glib string representation to std::string and free the original.
  *
  * @param text glib string representation
  * @return optional copied std::string
  * @note adjusted from https://github.com/mysql/mysql-workbench/blob/418f54b81440b974dba1ddc4a923334e0759fac5/tools/mga/src/aal/linux/accessible.cpp#L112
*/
std::optional<std::string> ConvertStringAndFree(gchar *text);
} // namespace atspi_utils

