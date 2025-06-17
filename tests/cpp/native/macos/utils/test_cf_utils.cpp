#include <gtest/gtest.h>
#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <string>

#include "src/native/macos/utils/cf_utils.h"

TEST(CFUtilsTest, ToStringNormal) {
  const CFStringRef string_ref = CFStringCreateWithCString(nullptr, "Hello", kCFStringEncodingUTF8);

  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_TRUE(actual_string.has_value());
  EXPECT_EQ(actual_string.value(), "Hello");
  EXPECT_EQ(std::strlen(actual_string.value().data()), 5);
  EXPECT_EQ(actual_string.value().length(), 5);

  CFRelease(string_ref);
}

TEST(CFUtilsTest, ToStringEmpty) {
  const CFStringRef string_ref = CFStringCreateWithCString(nullptr, "", kCFStringEncodingUTF8);

  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_TRUE(actual_string.has_value());
  EXPECT_EQ(actual_string.value(), "");
  EXPECT_EQ(std::strlen(actual_string.value().data()), 0);
  EXPECT_EQ(actual_string.value().length(), 0);

  CFRelease(string_ref);
}

TEST(CFUtilsTest, ToStringMalformed) {
  const CFStringRef string_ref = CFStringCreateWithCString(nullptr, "\0\0\0\0\0", kCFStringEncodingUTF8);

  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_TRUE(actual_string.has_value());
  EXPECT_EQ(actual_string.value(), "");
  EXPECT_EQ(std::strlen(actual_string.value().data()), 0);
  EXPECT_EQ(actual_string.value().length(), 0);

  CFRelease(string_ref);
}

TEST(CFUtilsTest, ToStringNoOptimization) {
  const CFStringRef string_ref = CFStringCreateWithCString(nullptr, "Hello", kCFStringEncodingASCII);

  // Assert no optimization is done by CoreFoundation
  EXPECT_EQ(CFStringGetCStringPtr(string_ref, kCFStringEncodingUTF8), nullptr);
  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_TRUE(actual_string.has_value());
  EXPECT_EQ(actual_string.value(), "Hello");
  EXPECT_EQ(std::strlen(actual_string.value().data()), 5);
  EXPECT_EQ(actual_string.value().length(), 5);

  CFRelease(string_ref);
}

TEST(CFUtilsTest, ToStringNoOptimizationEmbeddedNull) {
  const char data[] = {'H', 'e', 'l', 'l', 'o', '\0', 'x'};
  CFStringRef string_ref = CFStringCreateWithBytes(nullptr, reinterpret_cast<const UInt8*>(data), sizeof(data),
                                          kCFStringEncodingUTF8, false);

  // Assert no optimization is done by CoreFoundation
  EXPECT_EQ(CFStringGetCStringPtr(string_ref, kCFStringEncodingUTF8), nullptr);
  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_TRUE(actual_string.has_value());
  EXPECT_EQ(actual_string.value(), "Hello");
  EXPECT_EQ(std::strlen(actual_string.value().data()), 5);
  EXPECT_EQ(actual_string.value().length(), 5);

  CFRelease(string_ref);
}

TEST(CFUtilsTest, ToStringNullptr) {
  auto actual_string = cf_utils::ToString(nullptr);

  EXPECT_FALSE(actual_string.has_value());
}

TEST(CFUtilsTest, ToStringEncodingFails) {
  const unsigned char invalid_utf8[] = {0xFF, 0xFE, 0xFD};  // Invalid UTF-8

  CFStringRef string_ref = CFStringCreateWithBytes(nullptr, invalid_utf8, sizeof(invalid_utf8),
                                                   kCFStringEncodingUTF8, false);

  auto actual_string = cf_utils::ToString(string_ref);

  EXPECT_FALSE(actual_string.has_value());

  // Releasing string_ref will crash
  // CFRelease(string_ref);
}
