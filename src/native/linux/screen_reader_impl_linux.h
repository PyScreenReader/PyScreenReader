#pragma once

#include "include/vwidget/widgets/virtual_root_widget.h"
#include <atspi/atspi.h>
#include <memory>

namespace screen_reader {
class ScreenReaderImpl {
public:
  ScreenReaderImpl() = default;
  ~ScreenReaderImpl() = default;

  [[nodiscard]] std::shared_ptr<VirtualRootWidget>
  getVirtualWidgetTreeByPID(const std::string &pid) const;
  [[nodiscard]] std::shared_ptr<VirtualRootWidget>
  getVirtualWidgetTreeByTitle(const std::string &title) const;
  [[nodiscard]] std::shared_ptr<VirtualRootWidget>
  getVirtualWidgetTreeByClassName(const std::string &className) const;

private:
  AtspiAccessible *findAtspiAccessibleByPID(AtspiAccessible *node,
                                            const std::string &pid) const;
};
} // namespace screen_reader