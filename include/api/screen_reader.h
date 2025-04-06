#pragma once

#include "vwidget/widgets/virtual_root_widget.h"
#include "native/macos/screen_reader_impl.h"
#include <string>

class ScreenReader {
private:
    ScreenReaderImpl screenReaderImpl;
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
};