#include <glib-object.h>
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "src/native/linux/screen_reader_impl_linux.h"
#include "src/native/linux/vwidget_generator_linux.h"

namespace screen_reader {

ScreenReaderImpl::ScreenReaderImpl() {
  int init_error_code = atspi_init();

  if (init_error_code == 1) {
    std::cerr << "SPI is already initialized, using the existing" << std::endl;
  } else if (init_error_code != 0) {
    throw std::runtime_error("Failed to initialize at-spi API. Error code: " +
                             std::to_string(init_error_code));
  }
}

ScreenReaderImpl::~ScreenReaderImpl() {
  atspi_exit();
}

std::shared_ptr<VirtualWidget> ScreenReaderImpl::GetVirtualWidgetTreeByPID(const pid_t pid) const {
  // According to ATSPI documentation, any desktop index different from 0 will return NULL.
  // https://docs.gtk.org/atspi2/func.get_desktop.html
  AtspiAccessible* desktop = atspi_get_desktop(0);
  if (desktop == nullptr) {
    throw std::runtime_error("Cannot connect to desktop");
  }

  // TODO: (#46) remove redundant conversion for pid
  AtspiAccessible* target_app = FindAtspiAccessibleByPID(desktop, pid);
  g_object_unref(desktop);

  std::shared_ptr<VirtualWidget> widget_tree = vwidget_generator::GenerateVWidgetTree(target_app);
  g_object_unref(target_app);
  return widget_tree;
}

AtspiAccessible* ScreenReaderImpl::FindAtspiAccessibleByPID(AtspiAccessible* desktop,
                                                            pid_t target_pid) const {
  if (desktop == nullptr) {
    return nullptr;
  }

  GError* error = nullptr;
  size_t num_app = static_cast<size_t>(atspi_accessible_get_child_count(desktop, &error));

  if (error) {
    gint error_code = error->code;
    std::string error_message =
        error->message ? static_cast<std::string>(error->message) : "Unknown";
    g_error_free(error);

    std::stringstream error_message_stream;
    error_message_stream << "Error occurs when counting number of applications. Error code: "
                         << error_code;
    error_message_stream << " Error message: " << error_message;
    throw std::runtime_error(error_message_stream.str());
  }

  AtspiAccessible* target_app = nullptr;
  std::vector<pid_t> available_apps;

  for (size_t i = 0; i < num_app; i++) {
    AtspiAccessible* app = atspi_accessible_get_child_at_index(desktop, i, nullptr);
    pid_t pid = static_cast<pid_t>(atspi_accessible_get_process_id(app, nullptr));
    available_apps.push_back(pid);
    if (pid == target_pid) {
      target_app = app;
      break;
    }

    g_object_unref(app);
  }

  if (target_app == nullptr) {
    std::stringstream stream;
    stream << "Cannot find the target app with PID: ";
    stream << std::to_string(target_pid);
    stream << ". Available PIDs: ";
    for (const auto& pid : available_apps) {
      stream << std::to_string(pid) << ",";
    }
    throw std::runtime_error(stream.str());
  }
  return target_app;
}
}  // namespace screen_reader
