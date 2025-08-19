#include <ApplicationServices/ApplicationServices.h>
#include <gtest/gtest.h>

#include "src/native/macos/utils/system_utils.h"

TEST(SystemUtilsTest, ValidPIDReturnsAXUIElementRef) {
  pid_t current_pid = getpid();
  std::string pid_str = std::to_string(current_pid);
  AXUIElementRef element = system_utils::GetAXUIElementRefByPID(pid_str);
  ASSERT_NE(element, nullptr);
  CFRelease(element);
}

TEST(SystemUtilsTest, InvalidPIDThrows) {
  std::string invalid_pid = "abc123";
  EXPECT_THROW({ system_utils::GetAXUIElementRefByPID(invalid_pid); }, std::invalid_argument);
}

TEST(SystemUtilsTest, NonExistentPIDStillReturnsNonNullElement) {
  // AXUIElementCreateApplication still returns a valid ref even for dead PIDs
  std::string fake_pid = "999999";
  AXUIElementRef element = system_utils::GetAXUIElementRefByPID(fake_pid);
  ASSERT_NE(element, nullptr);
  CFRelease(element);
}
