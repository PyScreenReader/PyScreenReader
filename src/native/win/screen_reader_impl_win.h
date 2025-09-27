#pragma once
#include <memory>

#include <uiautomationclient.h>
#include <string>

#include "include/vwidget/widgets/virtual_window_widget.h"
#include "src/base/types.h"

namespace screen_reader {
class ScreenReaderImpl {
 public:
  ScreenReaderImpl();
  ~ScreenReaderImpl();
  std::shared_ptr<VirtualWidget> FromPID(const pid_t pid) const;

 private:
  IUIAutomation* automation_;
  IUIAutomationElement* root_element_;
};
}  // namespace screen_reader