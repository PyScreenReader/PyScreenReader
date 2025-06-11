#include <gtest/gtest.h>
#include "include/api/screen_reader.h"

class ScreenReaderTest : public ::testing::Test {
 protected:
  const std::string TEST_PID = "20880";

  void SetUp() override {}
  ScreenReader screen_reader_;
  std::shared_ptr<VirtualWidget> root_ = nullptr;
};

TEST_F(ScreenReaderTest, DefaultConstruction) {
  root_ = screen_reader_.GetVirtualWidgetTreeByPID(TEST_PID);
  EXPECT_EQ(root_->GetWidgetName(), "VirtualWindowWidget");
}
