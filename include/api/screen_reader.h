#pragma once

#include <memory>

#include "include/vwidget/widgets/virtual_root_widget.h"
#include <string>

#if defined(__APPLE__)
#include "src/native/macos/screen_reader_impl_mac.h"
#elif defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN__)
#include "src/native/win/screen_reader_impl_win.h"
#endif

class ScreenReaderImpl;

class ScreenReader {
public:
    ScreenReader() = default;
    ~ScreenReader() = default;
    /**
 * Retrieves the virtual widget tree associated with the specified process ID (PID).
 *
 * @param pid The process ID used to identify the target application
 * @return pointer to the VirtualRootWidget corresponding to the given PID
 */
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByPID(const std::string &pid) const;

/**
 * Retrieves the virtual widget tree associated with the specified window title.
 *
 * @param title The window title used to identify the target application
 * @return pointer to the VirtualRootWidget corresponding to the given title
 */
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByTitle(const std::string &title) const;

/**
 * Retrieves the virtual widget tree associated with the specified window class name.
 *
 * @param className The window class name used to identify the target application
 * @return pointer to the VirtualRootWidget corresponding to the given class name
 */
    std::shared_ptr<VirtualRootWidget> getVirtualWidgetTreeByClassName(const std::string &className) const;

private:
    screen_reader::ScreenReaderImpl screenReaderImpl;
};