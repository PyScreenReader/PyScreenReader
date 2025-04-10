#include "native/macos/utils/system_utils.h"
#if __APPLE__
AXUIElementRef SystemUtils::getAXUIElementRefByPID(const std::string& pid) {
    pid_t pidNum;
    try {
        pidNum = std::stoi(pid);
    } catch (const std::exception& e) {
        throw std::invalid_argument("Invalid PID format: " + pid);
    }
    AXUIElementRef app = AXUIElementCreateApplication(pidNum);
    return app;
}
#endif