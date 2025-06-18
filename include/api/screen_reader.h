#pragma once

#include <memory>
#include <string>

#include "src/base/build_flags.h"
#include "include/vwidget/virtual_widget.h"

#if defined(MAC_OS)
#include "src/native/macos/screen_reader_impl_mac.h"
#elif defined(WIN_OS)
#include "src/native/win/screen_reader_impl_win.h"
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
  [[nodiscard]] std::shared_ptr<VirtualWidget>
  GetVirtualWidgetTreeByPID(const std::string &pid) const;

  /**
   * Retrieves the virtual widget tree associated with the specified window
   * title.
   *
   * @param title The window title used to identify the target application
   * @return pointer to the VirtualWidget corresponding to the given title
   */
  [[nodiscard]] std::shared_ptr<VirtualWidget>
  GetVirtualWidgetTreeByTitle(const std::string &title) const;

  /**
   * Retrieves the virtual widget tree associated with the specified window
   * class name.
   *
   * @param class_name The window class name used to identify the target
   * application
   * @return pointer to the VirtualWidget corresponding to the given class
   * name
   */
  [[nodiscard]] std::shared_ptr<VirtualWidget>
  GetVirtualWidgetTreeByClassName(const std::string &class_name) const;

private:
  screen_reader::ScreenReaderImpl screen_reader_impl_;
};
