#include <glib-object.h>

#include "src/native/linux/utils/atspi_utils.h"

std::optional<std::string> atspi_utils::GetPrimaryText(AtspiAccessible* element) {
  if (!element)
    return std::nullopt;

  AtspiText *text_interface = atspi_accessible_get_text_iface(element);

  if (!text_interface)
    return std::nullopt;

  GError *char_count_error = nullptr;
  gint num_chars = atspi_text_get_character_count(
    text_interface,
    &char_count_error
  );

  if (char_count_error) {
    g_error_free(char_count_error);
    return std::nullopt;
  }

  GError *get_text_error = nullptr;
  gchar *text = atspi_text_get_text(text_interface, 0, num_chars, &get_text_error);

  if (get_text_error) {
    g_error_free(get_text_error);
    return std::nullopt;
  }

  return atspi_utils::ConvertStringAndFree(text);
}


std::optional<std::string> atspi_utils::GetHelpText(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  GError *get_text_error = nullptr;
  gchar *help_text = atspi_accessible_get_help_text(element, &get_text_error);
  if (get_text_error) {
    g_error_free(get_text_error);
    return std::nullopt;
  }

  if (help_text && help_text[0] != '\0')
    return atspi_utils::ConvertStringAndFree(help_text);

  gchar *desc_text = atspi_accessible_get_description(element, &get_text_error);
  if (get_text_error) {
    g_error_free(get_text_error);
    return std::nullopt;
  }

  return atspi_utils::ConvertStringAndFree(desc_text);
}


std::optional<AtspiRole> atspi_utils::GetRole(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  GError *get_role_error = nullptr;
  AtspiRole element_role = atspi_accessible_get_role(element, &get_role_error);

  if (get_role_error) {
    g_error_free(get_role_error);
    return std::nullopt;
  }

  return element_role;
}

std::optional<std::string> atspi_utils::GetRoleName(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  auto role_opt = atspi_utils::GetRole(element);
  if (!role_opt.has_value())
    return std::nullopt;

  gchar *role_name = atspi_role_get_name(role_opt.value());
  return atspi_utils::ConvertStringAndFree(role_name);
}


bool atspi_utils::GetVisibility(AtspiAccessible *element) {
  if (!element)
    return false;

  AtspiStateSet *states = atspi_accessible_get_state_set(element);
  // having "VISIBLE" state does not guarantee the component is visible to user
  // so we have to check "SHOWING" state as well.
  // https://gnome.pages.gitlab.gnome.org/at-spi2-core/libatspi/enum.StateType.html#visible
  bool is_visible = atspi_state_set_contains(states, ATSPI_STATE_VISIBLE);
  // https://gnome.pages.gitlab.gnome.org/at-spi2-core/libatspi/enum.StateType.html#showing
  bool is_showing = atspi_state_set_contains(states, ATSPI_STATE_SHOWING);

  g_object_unref(states);
  return is_visible && is_showing;
}


std::optional<AtspiPoint*> atspi_utils::GetPosition(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  AtspiComponent *component = atspi_accessible_get_component(element);

  GError *get_position_error = nullptr;
  AtspiPoint *coords = atspi_component_get_position(component, ATSPI_COORD_TYPE_SCREEN, &get_position_error);

  if (get_position_error) {
    g_error_free(get_position_error);
    return std::nullopt;
  }

  return coords;
}


std::optional<AtspiPoint*> atspi_utils::GetDimension(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  AtspiComponent *component = atspi_accessible_get_component(element);

  GError *get_dimension_error = nullptr;
  AtspiPoint *dim = atspi_component_get_size(component, &get_dimension_error);

  if (get_dimension_error) {
    g_error_free(get_dimension_error);
    return std::nullopt;
  }

  return dim;
}


std::optional<unsigned int> atspi_utils::GetChildrenCount(AtspiAccessible *element) {
  if (!element)
    return std::nullopt;

  GError *count_error = nullptr;
  gint count = atspi_accessible_get_child_count(element, &count_error);

  if (count_error) {
    g_error_free(count_error);
    return std::nullopt;
  }

  return static_cast<unsigned int>(count);
}


std::optional<AtspiAccessible*> atspi_utils::GetChildAtIndex(AtspiAccessible *element, unsigned int child_index) {
  if (!element)
    return std::nullopt;

  GError *get_child_error = nullptr;
  AtspiAccessible *child = atspi_accessible_get_child_at_index(element, child_index, &get_child_error);

  if (get_child_error) {
    g_error_free(get_child_error);
    return std::nullopt;
  }

  return child;
}


std::optional<std::string> atspi_utils::ConvertStringAndFree(gchar *text) {
  if (!text)
    return std::nullopt;
  std::string result(text);
  g_free(text);
  return result;
}
