#pragma once
#include <memory>

#include <uiautomationclient.h>
#include <string>
#include "include/vwidget/widgets/virtual_root_widget.h"

namespace screen_reader {
class ScreenReaderImpl {
 public:
  ScreenReaderImpl();
  ~ScreenReaderImpl();
  std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByPID(const std::string& pid) const;
  std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByTitle(const std::string& title) const;
  std::shared_ptr<VirtualRootWidget> GetVirtualWidgetTreeByClassName(
      const std::string& class_name) const;

 private:
  IUIAutomation* automation_;
  IUIAutomationElement* root_element_;
};
}  // namespace screen_reader