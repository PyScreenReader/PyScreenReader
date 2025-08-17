#include <gtest/gtest.h>
#include <string>

#include "src/native/linux/screen_reader_impl_linux.h"

/**
 * This is a test case that only serves as a sanity check.
 *
 * In most cases, we could also use this as a handy entry point
 * for debugging with IDE breakpoints.
 */
TEST(ScreenReaderImplLinuxTest, TestPidSanityCheck) {
  screen_reader::ScreenReaderImpl::GetVirtualWidgetTreeByPID("82534");
}
