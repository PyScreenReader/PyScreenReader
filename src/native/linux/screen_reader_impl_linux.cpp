#include "screen_reader_impl_linux.h"
// #include "vwidget_generator.h"
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <glib-object.h>

namespace screen_reader {

ScreenReaderImpl::ScreenReaderImpl() {
  // FIXME: we should only call atspi_init() once per process.
  // Since our user might initialize multiple screen readers, we should keep this idempotent.
  // Related to above: we will also need to call atspi_exit() at the right time.
  int init_error_code = atspi_init();

  if (init_error_code == 1) {
    std::cerr << "SPI is already initialized, using the existing" << std::endl;
  } else if (init_error_code != 0) {
    throw std::runtime_error("Failed to initialize at-spi API. Error code: " + std::to_string(init_error_code));
  }
}

std::shared_ptr<VirtualWidget>
ScreenReaderImpl::GetVirtualWidgetTreeByPID(const std::string &pid) const {
  // According to ATSPI documentation, any desktop index different from 0 will return NULL.
  // https://docs.gtk.org/atspi2/func.get_desktop.html
  AtspiAccessible *desktop = atspi_get_desktop(0);
  if (desktop == nullptr) {
    throw std::runtime_error("Cannot connect to desktop");
  }

  // TODO (#46) remove redundant conversion for pid
  AtspiAccessible *target_app = FindAtspiAccessibleByPID(desktop, std::stoi(pid));

  std::shared_ptr<VirtualWidget> widget_tree; // = generator::GenerateVWidgetTree(target_node);
  g_object_unref(desktop);
  return widget_tree;
}

AtspiAccessible *
ScreenReaderImpl::FindAtspiAccessibleByPID(AtspiAccessible *desktop, pid_t target_pid) const {
  if (desktop == nullptr) {
    return nullptr;
  }

  GError *error = nullptr;
  size_t num_app = static_cast<size_t>(atspi_accessible_get_child_count(desktop, &error));

  if (error) {
    gint error_code = error->code;
    std::string error_message = error->message ? static_cast<std::string>(error->message) : "Unknown";
    g_error_free(error);

    std::stringstream error_message_stream;
    error_message_stream << "Error occurs when counting number of applications. Error code: " << error_code;
    error_message_stream << " Error message: " << error_message;
    throw std::runtime_error(error_message_stream.str());
  }

  AtspiAccessible *target_app = nullptr;

  for (size_t i = 0; i < num_app; i++) {
    AtspiAccessible *app = atspi_accessible_get_child_at_index(desktop, i, nullptr);
    pid_t pid = static_cast<pid_t>(atspi_accessible_get_process_id(app, nullptr));
    if (pid == target_pid) {
      target_app = app;
      break;
    }

    g_object_unref(app);
  }

  if (target_app == nullptr)
    throw std::runtime_error("Cannot find the target app with PID: " + std::to_string(target_pid));

  return target_app;
}
} // namespace screen_reader

