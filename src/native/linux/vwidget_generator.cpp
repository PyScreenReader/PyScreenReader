#include "vwidget_generator.h"
#include <cassert>

namespace generator {

std::shared_ptr<VirtualRootWidget>
GenerateVWidgetTree(AtspiAccessible *rootElement) {
  std::shared_ptr<VirtualWidget> root_widget =
      TraverseDFSVWidgetTree(rootElement);
  return std::static_pointer_cast<VirtualRootWidget>(root_widget);
}

std::shared_ptr<VirtualWidget>
TraverseDFSVWidgetTree(AtspiAccessible *elem_atspi) {
  std::shared_ptr<VirtualWidget> elem = GetVWidget(elem_atspi);

  size_t num_children = atspi_accessible_get_child_count(elem_atspi, nullptr);
  for (size_t i = 0; i < num_children; i++) {
    AtspiAccessible *elem_child_atspi =
        atspi_accessible_get_child_at_index(elem_atspi, i, nullptr);
    std::shared_ptr<VirtualWidget> elem_child =
        TraverseDFSVWidgetTree(elem_child_atspi);

    elem_child->setParent(elem);
    elem->addChild(elem_child);
  }
  return elem;
}

// this function only handles properties of the element and not it's relation to
// other element in the graph, i.e. it doesn't set parent or children
std::shared_ptr<VirtualWidget> GetVWidget(AtspiAccessible *elem_atspi) {
  AtspiRole elem_role = atspi_accessible_get_role(elem_atspi, nullptr);
  std::string elem_name = std::string(atspi_role_get_name(elem_role));

  std::shared_ptr<VirtualWidget> elem;
  auto it = ROLE_TO_VWIDGET_MAP.find(elem_name);
  if (it != ROLE_TO_VWIDGET_MAP.end()) {
    elem = it->second(elem_atspi);
  } else {
    elem = ROLE_TO_VWIDGET_MAP.at(UNKNOWN_ROLE_ID)(elem_atspi);
  }

  elem->setTitleText(atspi_accessible_get_name(elem_atspi, nullptr));
  elem->setHelpText(atspi_accessible_get_help_text(elem_atspi, nullptr));

  AtspiStateSet *states = atspi_accessible_get_state_set(elem_atspi);
  bool isVisible = atspi_state_set_contains(states, ATSPI_STATE_VISIBLE);
  bool isShowing = atspi_state_set_contains(states, ATSPI_STATE_SHOWING);
  if (isVisible && isShowing) {
    AtspiComponent *comp = atspi_accessible_get_component(
        elem_atspi); // assuming VirtualWidget.x and y are the it's MINIMUM x
                     // and y coordinates, and not the center
    AtspiPoint *coords =
        atspi_component_get_position(comp, ATSPI_COORD_TYPE_SCREEN, nullptr);
    elem->setX(coords->x);
    elem->setY(coords->y);

    AtspiPoint *dims = atspi_component_get_size(comp, nullptr);
    elem->setWidth(dims->x);
    elem->setHeight(dims->y);
  }
  elem->setVisible(isVisible);

  return elem;
}

} // namespace generator