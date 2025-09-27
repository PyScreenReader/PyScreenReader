#include <ApplicationServices/ApplicationServices.h>
#include <gtest/gtest.h>

#include "src/native/macos/utils/system_utils.h"

TEST(SystemUtilsTest, ValidPIDReturnsAXUIElementRef) {
  pid_t current_pid = getpid();
  AXUIElementRef element = system_utils::GetAXUIElementRefByPID(current_pid);
  ASSERT_NE(element, nullptr);
  CFRelease(element);
}


TEST(SystemUtilsTest, NonExistentPIDStillReturnsNonNullElement) {
  // AXUIElementCreateApplication still returns a valid ref even for dead PIDs
  pid_t fake_pid = 999999;
  AXUIElementRef element = system_utils::GetAXUIElementRefByPID(fake_pid);
  ASSERT_NE(element, nullptr);
  CFRelease(element);
}
