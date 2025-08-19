#pragma once

#include <memory>
#include <string>

#include "include/vwidget/virtual_widget.h"
#include "src/base/build_flags.h"

#if defined(MAC_OS)
#include "src/native/macos/screen_reader_impl_mac.h"
#elif defined(WIN_OS)
#include "src/native/win/screen_reader_impl_win.h"
#elif defined(__linux__)
#include "src/native/linux/screen_reader_impl_linux.h"
#endif

class ScreenReaderImpl;

class ScreenReader {
 public:
  ScreenReader() = default;
  ~ScreenReader() = default;
  /**
   * Retrieves the virtual widget tree associated with the specified process ID
   * (PID).
   *
   * @param pid The process ID used to identify the target application
   * @return pointer to the VirtualWidget corresponding to the given PID
   */
  [[nodiscard]] std::shared_ptr<VirtualWidget> GetVirtualWidgetTreeByPID(
      const std::string& pid) const;

 private:
  screen_reader::ScreenReaderImpl screen_reader_impl_;
};
