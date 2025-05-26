#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <string>

namespace SystemUtils {
    AXUIElementRef GetAXUIElementRefByPID(const std::string &pid);
}
