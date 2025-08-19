#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <optional>
#include <string>

namespace system_utils {
/**
 * Get AXUIElement by process id.
 *
 * @param pid id of the process
 * @return AXUIElement (normally of role AXWindow) of the process. If the process is not
 *        found, it will return nullptr.
 * @throw std::invalid_argument if pid is not a valid number
 */
AXUIElementRef GetAXUIElementRefByPID(const std::string& pid);
}  // namespace system_utils
