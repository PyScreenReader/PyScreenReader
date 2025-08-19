#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <string>

#include "src/native/macos/utils/cf_utils.h"

/**
 * These test cases involve actual AXUIElement, which do not run in CI environment.
 */

class CFUtilsTest : public ::testing::Test {
 protected:
  static AXUIElementRef window_ref_;
  static CFStringRef dummy_attr_name_;

  static void SetUpTestSuite() {
    AssertPermission();
    dummy_attr_name_ =
        CFStringCreateWithCString(nullptr, "FakeAttributeName", kCFStringEncodingUTF8);
    window_ref_ = FindFirstWindowElement();
  }

  static void TearDownTestSuite() {
    CFRelease(window_ref_);
    CFRelease(dummy_attr_name_);
  }

  static void AssertPermission() {
    /**
     * Assert there is proper accessibility permission
     */
    CFStringRef keys[] = {kAXTrustedCheckOptionPrompt};
    CFBooleanRef values[] = {kCFBooleanTrue};
    CFDictionaryRef options =
        CFDictionaryCreate(kCFAllocatorDefault, reinterpret_cast<const void**>(keys),
                           reinterpret_cast<const void**>(values), 1,
                           &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    Boolean trusted = AXIsProcessTrustedWithOptions(options);
    CFRelease(options);
    if (!trusted) {
      throw std::logic_error("Current test case needs accessibility permission to run");
    }
  }

  static AXUIElementRef FindFirstWindowElement() {
    /**
     * Find first window element on system, so we can use it to test.
     */
    ProcessSerialNumber psn = {0, kNoProcess};
    while (GetNextProcess(&psn) == noErr) {
      pid_t pid = 0;
      if (GetProcessPID(&psn, &pid) != noErr)
        continue;

      AXUIElementRef app = AXUIElementCreateApplication(pid);
      if (!app)
        continue;

      auto windows_opt = cf_utils::GetAttribute<CFArrayRef>(app, kAXWindowsAttribute);
      CFRelease(app);
      if (!windows_opt.has_value())
        continue;

      CFArrayRef windows = windows_opt.value();
      CFIndex count = CFArrayGetCount(windows);
      for (CFIndex i = 0; i < count; i++) {
        AXUIElementRef window = (AXUIElementRef)CFArrayGetValueAtIndex(windows, i);

        auto role_opt = cf_utils::GetAttribute<std::string>(window, kAXRoleAttribute);
        if (role_opt.has_value() && role_opt.value() == "AXWindow") {
          CFRetain(window);
          CFRelease(windows);
          return window;
        }
      }
      CFRelease(windows);
    }
    return nullptr;
  }
};

AXUIElementRef CFUtilsTest::window_ref_ = nullptr;
CFStringRef CFUtilsTest::dummy_attr_name_ = nullptr;

TEST_F(CFUtilsTest, GetAttributeBool) {
  auto actual = cf_utils::GetAttribute<bool>(window_ref_, kAXFocusedAttribute);
  ASSERT_TRUE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeTargetIsNotBoolean) {
  auto actual = cf_utils::GetAttribute<bool>(window_ref_, kAXTitleAttribute);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeTargetDoesNotExist) {
  auto actual = cf_utils::GetAttribute<bool>(window_ref_, dummy_attr_name_);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeString) {
  auto actual = cf_utils::GetAttribute<std::string>(window_ref_, kAXRoleAttribute);
  ASSERT_TRUE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeStringTargetIsNotString) {
  auto actual = cf_utils::GetAttribute<std::string>(window_ref_, kAXFocusedApplicationAttribute);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeStringTargetDoesNotExist) {
  auto actual = cf_utils::GetAttribute<std::string>(window_ref_, dummy_attr_name_);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCFArray) {
  auto actual = cf_utils::GetAttribute<CFArrayRef>(window_ref_, kAXChildrenAttribute);
  ASSERT_TRUE(actual.has_value());
  CFRelease(actual.value());
}

TEST_F(CFUtilsTest, GetAttributeCFArrayTargetIsNotArray) {
  auto actual = cf_utils::GetAttribute<CFArrayRef>(window_ref_, kAXRoleAttribute);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCFArrayTargetDoesNotExist) {
  auto actual = cf_utils::GetAttribute<CFArrayRef>(window_ref_, dummy_attr_name_);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGPoint) {
  auto actual = cf_utils::GetAttribute<CGPoint>(window_ref_, kAXPositionAttribute);
  ASSERT_TRUE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGPointTargetIsNotPoint) {
  auto actual = cf_utils::GetAttribute<CGPoint>(window_ref_, kAXRoleAttribute);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGPointTargetDoesNotExist) {
  auto actual = cf_utils::GetAttribute<CGPoint>(window_ref_, dummy_attr_name_);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGSize) {
  auto actual = cf_utils::GetAttribute<CGSize>(window_ref_, kAXSizeAttribute);
  ASSERT_TRUE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGSizeTargetIsNotPoint) {
  auto actual = cf_utils::GetAttribute<CGSize>(window_ref_, kAXRoleAttribute);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeCGSizeTargetDoesNotExist) {
  auto actual = cf_utils::GetAttribute<CGSize>(window_ref_, dummy_attr_name_);
  ASSERT_FALSE(actual.has_value());
}

TEST_F(CFUtilsTest, GetAttributeNotSupportedType) {
  ASSERT_THROW({ cf_utils::GetAttribute<long>(window_ref_, kAXRoleAttribute); }, std::logic_error);
}
