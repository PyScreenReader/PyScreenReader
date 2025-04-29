#include "include/api/screen_reader.h"
#include <gtest/gtest.h>

class ScreenReaderTest : public ::testing::Test
{
protected:
    const std::string TEST_PID = "20880";

    void SetUp() override {}
    ScreenReader screen_reader_;
    std::shared_ptr<VirtualRootWidget> root_ = nullptr;
};


TEST_F(ScreenReaderTest, DefaultConstruction)
{
    root_ = screen_reader_.getVirtualWidgetTreeByPID(TEST_PID);
    EXPECT_EQ(root_->getWidgetName(), "VirtualRootWidget");
}
