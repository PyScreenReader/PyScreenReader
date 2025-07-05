#include <glib-object.h>

#include "src/native/linux/utils/atspi_utils.h"

std::optional<std::string> atspi_utils::get_primary_text(AtspiAccessible* element) {
  if (!element)
    return std::nullopt;

  AtspiText *text_interface = atspi_accessible_get_text_iface(accessible);
  GError *char_count_error = nullptr;
  gint num_chars = atspi_text_get_character_count(
    text_interface,
    &char_count_error
  );

  if (char_count_error)
    return std::nullopt;

  gchar *text = nullptr;
  GError *get_text_error = nullptr;
  atspi_text_get_text(text_interface, 0, char_count_error, &get_text_error);

  if (get_text_error)
    return std::nullopt;

  return convert_string_and_free(text);
}


std::optional<std::string> get_help_text(AtspiAccessible *element) {
  return std::nullopt;
}


std::optional<std::string> get_role_name(AtspiAccessible *element) {
  return std::nullopt;
}


bool get_visibility(AtspiAccessible *element) {
  return true;
}


std::optional<AtspiPoint*> get_position(AtspiAccessible *element) {
  return std::nullopt;
}


std::optional<AtspiPoint*> get_dimension(AtspiAccessible *element) {
  return std::nullopt;
}


std::string atspi_utils::convert_string_and_free(gchar *text) {
  std::string result(text);
  g_free(text);
  return result;
}
