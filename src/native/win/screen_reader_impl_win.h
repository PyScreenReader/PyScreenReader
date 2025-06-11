#pragma once
#include <memory>

#include <uiautomationclient.h>
#include <string>
#include "include/vwidget/widgets/virtual_window_widget.h"

namespace screen_reader {
class ScreenReaderImpl {
 public:
  ScreenReaderImpl();
  ~ScreenReaderImpl();
  std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByPID(const std::string& pid) const;
  std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByTitle(const std::string& title) const;
  std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByClassName(
      const std::string& class_name) const;

 private:
  IUIAutomation* automation_;
  IUIAutomationElement* root_element_;
};
}  // namespace screen_reader