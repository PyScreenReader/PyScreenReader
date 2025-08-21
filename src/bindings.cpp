#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "include/vwidget/numeric_value_widget.h"
#include "include/vwidget/virtual_widget.h"

#include "include/api/screen_reader.h"
#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_group_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_menu_widget.h"
#include "include/vwidget/widgets/virtual_progress_bar_widget.h"
#include "include/vwidget/widgets/virtual_scrollbar_widget.h"
#include "include/vwidget/widgets/virtual_slider_widget.h"
#include "include/vwidget/widgets/virtual_spinner_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"

namespace bindings {
namespace py = pybind11;

/**
 * Bind all virtual widgets
 *
 * @param root_module root project module
 */
void BindVirtualWidgets(py::module_& root_module) {
  py::module_ module = root_module.def_submodule(
      "virtual_widgets", "A submodule containing virtual widgets definitions");
  // Orientation
  py::enum_<Orientation>(module, "Orientation", R"doc(
Enum representing the orientation of widgets.
)doc")
      .value("HORIZONTAL", Orientation::HORIZONTAL, "Horizontal orientation.")
      .value("VERTICAL", Orientation::VERTICAL, "Vertical orientation.")
      .export_values();

  // VirtualWidget
  py::class_<VirtualWidget, std::shared_ptr<VirtualWidget>>(module, "VirtualWidget", R"doc(
Represents a virtual UI widget.

This class provides an abstraction for a UI widget, supporting properties such as text, coordinates,
dimensions, visibility, focus state, and parent/child relationships.
)doc")
      .def("get_title_text", &VirtualWidget::GetTitleText, R"doc(
Get title text.

Title text is a string that represents the primary text content of the widget.
- It can be the content string on the button, which says "Click me"
- It can be the string that a text input is displaying (if any)

:return: Title text string.
)doc")
      .def("set_title_text", &VirtualWidget::SetTitleText, py::arg("title_text"), R"doc(
Set title text.

See also: get_title_text()

:param title_text: Title text string.
)doc")
      .def("get_help_text", &VirtualWidget::GetHelpText, R"doc(
Get help text.

Help text is generally the secondary text content in a widget.
When you hover the cursor over widgets, if a tooltip pops up,
the tooltip content will be considered a help text.

:return: Help text.
)doc")
      .def("set_help_text", &VirtualWidget::SetHelpText, py::arg("help_text"), R"doc(
Set help text.

See also: get_help_text()

:param help_text: Help text string.
)doc")
      .def("get_native_name", &VirtualWidget::GetNativeName, R"doc(
Get name of the native widget this virtual widget is mapped from.

:return: Native widget name.
)doc")
      .def("set_native_name", &VirtualWidget::SetNativeName, py::arg("native_name"), R"doc(
Set native widget name.

See also: get_native_name()

:param native_name: Name of the native widget this virtual widget is mapped from.
)doc")
      .def("get_x", &VirtualWidget::GetX, R"doc(
Get the X coordinate of the top-left corner of the widget relative to the screen.

The top-left corner of the screen is considered the origin.

:return: X coordinate.
)doc")
      .def("set_x", &VirtualWidget::SetX, py::arg("x_coord"), R"doc(
Set the X coordinate of the top-left corner of the widget.

:param x_coord: X coordinate.
)doc")
      .def("get_y", &VirtualWidget::GetY, R"doc(
Get the Y coordinate of the top-left corner of the widget relative to the screen.

The top-left corner of the screen is considered the origin.

:return: Y coordinate.
)doc")
      .def("set_y", &VirtualWidget::SetY, py::arg("y_coord"), R"doc(
Set the Y coordinate of the top-left corner of the widget.

:param y_coord: Y coordinate.
)doc")
      .def("get_width", &VirtualWidget::GetWidth, R"doc(
Get the width of the current widget.

:return: Width of the widget.
)doc")
      .def("set_width", &VirtualWidget::SetWidth, py::arg("width"), R"doc(
Set the width of the current widget.

:param width: Width of the widget.
)doc")
      .def("get_height", &VirtualWidget::GetHeight, R"doc(
Get the height of the current widget.

:return: Height of the widget.
)doc")
      .def("set_height", &VirtualWidget::SetHeight, py::arg("height"), R"doc(
Set the height of the current widget.

:param height: Height of the widget.
)doc")
      .def("is_visible", &VirtualWidget::IsVisible, R"doc(
Get whether the current widget is visible to the user.

:return: True if visible, False otherwise.
)doc")
      .def("set_visible", &VirtualWidget::SetVisible, py::arg("visible"), R"doc(
Set whether the current widget is visible to the user.

:param visible: True if visible, False otherwise.
)doc")
      .def("is_focused", &VirtualWidget::IsFocused, R"doc(
Get whether the current widget is focused.

:return: True if focused, False otherwise.
)doc")
      .def("set_focused", &VirtualWidget::SetFocused, py::arg("focused"), R"doc(
Set whether the current widget is focused.

:param focused: True if focused, False otherwise.
)doc")
      .def("get_parent", &VirtualWidget::GetParent, R"doc(
Get the parent widget of the current widget.

:return: Parent widget.
)doc")
      .def("set_parent", &VirtualWidget::SetParent, py::arg("parent"), R"doc(
Set the parent widget of the current widget.

:param parent: Parent widget.
)doc")
      .def("get_child", &VirtualWidget::GetChild, py::arg("index"), R"doc(
Get the child widget at the given index (starting from 0).

Throws an out_of_range exception if there are not that many children.

:param index: Index of the child widget.
:return: Child widget at the given index.
)doc")
      .def("add_child", &VirtualWidget::AddChild, py::arg("child"), R"doc(
Add a child widget to this widget.

Note: This does not automatically set the child widget's parent. To preserve tree structure,
you should also call set_parent() on the child widget to assign this widget as its parent.

:param child: Child widget.
)doc")
      .def("get_widget_name", &VirtualWidget::GetWidgetName, R"doc(
Get the name of the current virtual widget in UpperCamelCase.

Examples: "VirtualButtonWidget", "VirtualTextWidget", etc.

:return: Current virtual widget name.
)doc")
      .def("get_children", &VirtualWidget::GetChildren, R"doc(
Get all children of this widget in the tree.

:return: List of all children widgets.
)doc")
      .def("__repr__", &VirtualWidget::ToString)
      .def("__str__", &VirtualWidget::ToString);

  // NumericValueWidget
  py::class_<NumericValueWidget, VirtualWidget, std::shared_ptr<NumericValueWidget>>(
      module, "NumericValueWidget", R"doc(
A widget that represents a numeric value with optional min/max bounds.
)doc")
      .def("get_value", &NumericValueWidget::GetValue, R"doc(
Get value contained in the widget.

:return: Value contained in the widget.
)doc")
      .def("set_value", &NumericValueWidget::SetValue, py::arg("value"), R"doc(
Set value contained in the widget.

:param value: Number value.
)doc")
      .def("get_min_value", &NumericValueWidget::GetMinValue, R"doc(
Get lower bound of the value.

:return: Minimum value of the range.
)doc")
      .def("set_min_value", &NumericValueWidget::SetMinValue, py::arg("min_value"), R"doc(
Set lower bound of the value.

:param min_value: Minimum value of the range.
)doc")
      .def("get_max_value", &NumericValueWidget::GetMaxValue, R"doc(
Get upper bound of the value.

:return: Maximum value of the range.
)doc")
      .def("set_max_value", &NumericValueWidget::SetMaxValue, py::arg("max_value"), R"doc(
Set upper bound of the value.

:param max_value: Maximum value of the range.
)doc");

  // VirtualButtonWidget
  py::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(
      module, "VirtualButtonWidget", R"doc(
A widget representing a button widget.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualButtonWidget instance.
)doc");

  // VirtualMenuItemWidget
  py::class_<VirtualMenuItemWidget, VirtualWidget, std::shared_ptr<VirtualMenuItemWidget>>(
      module, "VirtualMenuItemWidget", R"doc(
A widget representing a menu item widget.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualMenuItemWidget instance.
)doc");

  // VirtualMenuWidget
  py::class_<VirtualMenuWidget, VirtualWidget, std::shared_ptr<VirtualMenuWidget>>(
      module, "VirtualMenuWidget", R"doc(
A widget representing a menu widget.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualMenuWidget instance.
)doc");

  // VirtualProgressBarWidget
  py::class_<VirtualProgressBarWidget, NumericValueWidget,
             std::shared_ptr<VirtualProgressBarWidget>>(module, "VirtualProgressBarWidget", R"doc(
A widget representing a progress bar with a numeric value and orientation.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualProgressBarWidget instance.
)doc")
      .def("get_orientation", &VirtualProgressBarWidget::GetOrientation, R"doc(
Get the current orientation of the progress bar widget.

:return: Orientation of the widget.
)doc")
      .def("set_orientation", &VirtualProgressBarWidget::SetOrientation, py::arg("orientation"),
           R"doc(
Set the current orientation of the progress bar widget.

:param orientation: Orientation of the widget.
)doc");

  // VirtualScrollBarWidget
  py::class_<VirtualScrollbarWidget, NumericValueWidget, std::shared_ptr<VirtualScrollbarWidget>>(
      module, "VirtualScrollbarWidget", R"doc(
A widget representing a scrollbar widget with numeric value and orientation.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualScrollbarWidget instance.
)doc")
      .def("get_orientation", &VirtualScrollbarWidget::GetOrientation, R"doc(
Get the current orientation of the scrollbar widget.

:return: Orientation of the widget.
)doc")
      .def("set_orientation", &VirtualScrollbarWidget::SetOrientation, py::arg("orientation"),
           R"doc(
Set the current orientation of the scrollbar widget.

:param orientation: Orientation of the widget.
)doc");

  // VirtualSliderWidget
  py::class_<VirtualSliderWidget, NumericValueWidget, std::shared_ptr<VirtualSliderWidget>>(
      module, "VirtualSliderWidget", R"doc(
A widget representing a slider widget with numeric value and orientation.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualSliderWidget instance.
)doc")
      .def("get_orientation", &VirtualSliderWidget::GetOrientation, R"doc(
Get the current orientation of the slider widget.

:return: Orientation of the widget.
)doc")
      .def("set_orientation", &VirtualSliderWidget::SetOrientation, py::arg("orientation"), R"doc(
Set the current orientation of the slider widget.

:param orientation: Orientation of the widget.
)doc");

  // VirtualSpinnerWidget
  py::class_<VirtualSpinnerWidget, NumericValueWidget, std::shared_ptr<VirtualSpinnerWidget>>(
      module, "VirtualSpinnerWidget", R"doc(
A widget representing a numeric spinner widget.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualSpinnerWidget instance.
)doc");

  // VirtualTextInputWidget
  py::class_<VirtualTextInputWidget, VirtualWidget, std::shared_ptr<VirtualTextInputWidget>>(
      module, "VirtualTextInputWidget", R"doc(
A widget representing a text input field or text area.

Provides functionality for selection, cursor insertion point, and text area mode.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualTextInputWidget instance.
)doc")
      .def("get_selected_text", &VirtualTextInputWidget::GetSelectedText, R"doc(
Get the currently selected text in the input field.

:return: Selected text.
)doc")
      .def("set_selected_text", &VirtualTextInputWidget::SetSelectedText, py::arg("selected_text"),
           R"doc(
Set the currently selected text in the input field.

:param selected_text: Selected text string.
)doc")
      .def("get_insertion_point", &VirtualTextInputWidget::GetInsertionPoint, R"doc(
Get the current cursor location in the text input, represented by an index starting at 0.

For example, in "A|BCDEFG", this function returns 1.

:return: Current cursor index.
)doc")
      .def("set_insertion_point", &VirtualTextInputWidget::SetInsertionPoint,
           py::arg("insertion_point"), R"doc(
Set the current cursor location index in the text input.

See also: get_insertion_point()

:param insertion_point: Index starting from 0.
)doc")
      .def("is_text_area", &VirtualTextInputWidget::IsTextArea, R"doc(
Check if the current input widget is a text area.

:return: True if it's a text area, otherwise False.
)doc")
      .def("set_is_text_area", &VirtualTextInputWidget::SetIsTextArea, py::arg("is_text_area"),
           R"doc(
Set whether the input widget is a text area.

:param is_text_area: True if it's a text area, otherwise False.
)doc");

  // VirtualTextWidget
  py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(
      module, "VirtualTextWidget", R"doc(
A widget representing static text content with selectable regions.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualTextWidget instance.
)doc")
      .def("get_selected_text", &VirtualTextWidget::GetSelectedText, R"doc(
Get the cursor-selected text in the static text widget.

:return: Selected text.
)doc")
      .def("set_selected_text", &VirtualTextWidget::SetSelectedText, py::arg("selected_text"),
           R"doc(
Set the cursor-selected text in the static text widget.

:param selected_text: Selected text string.
)doc");

  // VirtualUnknownWidget
  py::class_<VirtualUnknownWidget, VirtualWidget, std::shared_ptr<VirtualUnknownWidget>>(
      module, "VirtualUnknownWidget", R"doc(
A virtual widget used as a fallback when no proper mapping exists from the native system widget.

This widget indicates that PyScreenReader cannot find a corresponding virtual widget
to represent the native widget.
)doc")
      .def(py::init<>(), R"doc(
Initialize a VirtualUnknownWidget instance.
)doc");

  // VirtualGroupWidget
  py::class_<VirtualGroupWidget, VirtualWidget, std::shared_ptr<VirtualGroupWidget>>(
      module, "VirtualGroupWidget", R"doc(
A VirtualGroupWidget represents a container-like native widget
that groups other widgets together in the accessibility tree.
Examples include rows, columns, lists, or generic grouping elements.

This abstraction models the hierarchical structure of the widget tree.
A VirtualGroupWidget typically does not handle direct user interactions itself.
If the native widget has specific interactive behaviors or functionalities,
it should generally not be mapped to a VirtualGroupWidget.
)doc")
      .def(py::init<>(), R"doc(
Initialize a VirtualGroupWidget instance.
)doc");

  // VirtualWindowWidget
  py::class_<VirtualWindowWidget, VirtualWidget, std::shared_ptr<VirtualWindowWidget>>(
      module, "VirtualWindowWidget", R"doc(
A widget representing a window, which can be modal or non-modal.
)doc")
      .def(py::init<>(), R"doc(
Create a new VirtualWindowWidget instance.
)doc")
      .def("is_modal", &VirtualWindowWidget::IsModal, R"doc(
Check if the current window is a modal.

Depending on the native system, a "modal" generally means a pop-up window that
appears on top of its main content and blocks user interaction with the rest of the UI
until the user completes specific actions or dismisses it.

:return: True if the window is modal, otherwise False.
)doc")
      .def("set_is_modal", &VirtualWindowWidget::SetIsModal, py::arg("is_modal"), R"doc(
Set whether the current window is a modal.

:param is_modal: True if the window is modal, otherwise False.
)doc");
}

/**
 * Bind all screen reader APIs
 *
 * @param root_module root project module
 */
void BindScreenReader(py::module_& root_module) {
  py::module_ module =
      root_module.def_submodule("screen_reader", "A submodule containing screen reader APIs");
  py::class_<ScreenReader>(module, "ScreenReader", R"doc(
ScreenReader provides access to virtual widget trees for applications identified by process ID.
)doc")
      .def(py::init<>(), R"doc(
Create a new ScreenReader instance.
)doc")
      .def("get_virtual_widget_tree_by_pid", &ScreenReader::GetVirtualWidgetTreeByPID,
           py::arg("pid"), py::return_value_policy::take_ownership, R"doc(
Retrieve the virtual widget tree associated with the specified process ID (PID).

:param pid: The process ID identifying the target application.
:return: Shared pointer to the VirtualWidget corresponding to the given PID.
)doc");
}
}  // namespace bindings

// ================================================
// Main Entry Point of Bindings
// ================================================

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

PYBIND11_MODULE(PyScreenReader, module) {
  // Bind python definitions
  bindings::BindVirtualWidgets(module);
  bindings::BindScreenReader(module);

// Inject version information
#ifdef VERSION_INFO
  module.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  module.attr("__version__") = "dev";
#endif
}