#include "src/native/macos/utils/system_utils.h"

AXUIElementRef system_utils::GetAXUIElementRefByPID(const std::string& pid) {
    pid_t pid_num;
    try {
        pid_num = std::stoi(pid);
    } catch (const std::exception& e) {
        throw std::invalid_argument("Invalid PID format: " + pid);
    }
    AXUIElementRef app = AXUIElementCreateApplication(pid_num);
    return app;
}
