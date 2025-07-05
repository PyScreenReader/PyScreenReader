#include <cassert>
#include <glib-object.h>
#include "src/native/linux/vwidget_generator_linux.h"

namespace generator {

std::shared_ptr<VirtualWidget>
GenerateVWidgetTree(AtspiAccessible *root_element) {
  if (!root_element)
    return nullptr;

  g_object_ref(root_element);


}

std::shared_ptr<VirtualWidget> MapToVWidget(AtspiAccessible *elem_atspi) {
  AtspiRole elem_role = atspi_accessible_get_role(elem_atspi, nullptr);
  std::string elem_name = std::string(atspi_role_get_name(elem_role));

  std::shared_ptr<VirtualWidget> element;
  auto it = kRoleWidgetMap.find(elem_name);
  if (it != kRoleWidgetMap.end()) {
    element = it->second(elem_atspi);
  } else {
    element = kRoleWidgetMap.at(UNKNOWN_ROLE_ID)(elem_atspi);
  }

  return element;

  // elem->setTitleText(atspi_accessible_get_name(elem_atspi, nullptr));
  // elem->setHelpText(atspi_accessible_get_help_text(elem_atspi, nullptr));
  //
  // AtspiStateSet *states = atspi_accessible_get_state_set(elem_atspi);
  // bool isVisible = atspi_state_set_contains(states, ATSPI_STATE_VISIBLE);
  // bool isShowing = atspi_state_set_contains(states, ATSPI_STATE_SHOWING);
  // if (isVisible && isShowing) {
  //   AtspiComponent *comp = atspi_accessible_get_component(
  //       elem_atspi); // assuming VirtualWidget.x and y are the it's MINIMUM x
  //                    // and y coordinates, and not the center
  //   AtspiPoint *coords =
  //       atspi_component_get_position(comp, ATSPI_COORD_TYPE_SCREEN, nullptr);
  //   elem->setX(coords->x);
  //   elem->setY(coords->y);
  //
  //   AtspiPoint *dims = atspi_component_get_size(comp, nullptr);
  //   elem->setWidth(dims->x);
  //   elem->setHeight(dims->y);
  // }
  // elem->setVisible(isVisible);
  //
  // return elem;
}

} // namespace generator
