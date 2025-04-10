
#if __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <string>

namespace SystemUtils {
    AXUIElementRef getAXUIElementRefByPID(const std::string &pid);
}
#endif