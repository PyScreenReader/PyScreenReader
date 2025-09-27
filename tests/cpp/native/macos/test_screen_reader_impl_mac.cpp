#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <gtest/gtest.h>
#include <string>

#include "src/native/macos/screen_reader_impl_mac.h"

/**
 * This is a test case that only serves as a sanity check.
 *
 * In most cases, we could also use this as a handy entry point
 * for debugging with IDE breakpoints.
 */
TEST(ScreenReaderImplMacTest, TestPidSanityCheck) {
  screen_reader::ScreenReaderImpl::FromPID(82534);
}
