#include "include/api/screen_reader.h"
#include <gtest/gtest.h>


// Demonstrate some basic assertions.
TEST(ScreenReaderTest, Construction) {
    auto screen_reader = ScreenReader();
    std::shared_ptr<VirtualRootWidget> root = screen_reader.getVirtualWidgetTreeByPID("20880");

    EXPECT_EQ(root->getWidgetName(), "VirtualRootWidget");
}