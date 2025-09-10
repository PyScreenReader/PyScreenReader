#include "src/native/macos/utils/system_utils.h"

AXUIElementRef system_utils::GetAXUIElementRefByPID(const pid_t pid) {
  AXUIElementRef app = AXUIElementCreateApplication(pid);
  return app;
}
