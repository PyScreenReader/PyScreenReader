#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/numeric_value_widget.h"

#include "include/vwidget/widgets/virtual_button_widget.h"
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
#include "include/api/screen_reader.h"

namespace bindings {
namespace py = pybind11;

/**
 * Bind all virtual widgets
 *
 * @param module python module object
 */
void BindVirtualWidgets(py::module_& module) {
  // Orientation
  py::enum_<Orientation>(module, "Orientation")
      .value("HORIZONTAL", Orientation::HORIZONTAL)
      .value("VERTICAL", Orientation::VERTICAL)
      .export_values();

  // VirtualWidget
  py::class_<VirtualWidget, std::shared_ptr<VirtualWidget>>(module, "VirtualWidget")
      .def("get_title_text", &VirtualWidget::GetTitleText)
      .def("set_title_text", &VirtualWidget::SetTitleText)
      .def("get_help_text", &VirtualWidget::GetHelpText)
      .def("set_help_text", &VirtualWidget::SetHelpText)
      .def("get_native_name", &VirtualWidget::GetNativeName)
      .def("set_native_name", &VirtualWidget::SetNativeName)
      .def("get_x", &VirtualWidget::GetX)
      .def("set_x", &VirtualWidget::SetX)
      .def("get_y", &VirtualWidget::GetY)
      .def("set_y", &VirtualWidget::SetY)
      .def("get_width", &VirtualWidget::GetWidth)
      .def("set_width", &VirtualWidget::SetWidth)
      .def("get_height", &VirtualWidget::GetHeight)
      .def("set_height", &VirtualWidget::SetHeight)
      .def("is_visible", &VirtualWidget::IsVisible)
      .def("set_visible", &VirtualWidget::SetVisible)
      .def("is_focused", &VirtualWidget::IsFocused)
      .def("set_focused", &VirtualWidget::SetFocused)
      .def("get_parent", &VirtualWidget::GetParent)
      .def("set_parent", &VirtualWidget::SetParent)
      .def("get_child", &VirtualWidget::GetChild)
      .def("add_child", &VirtualWidget::AddChild)
      .def("get_widget_name", &VirtualWidget::GetWidgetName)
      .def("get_children", &VirtualWidget::GetChildren)
      .def("__repr__", &VirtualWidget::ToString)
      .def("__str__", &VirtualWidget::ToString);

  // NumericValueWidget
  py::class_<NumericValueWidget, VirtualWidget,
                   std::shared_ptr<NumericValueWidget>>(module, "NumericValueWidget")
      .def("get_value", &NumericValueWidget::GetValue)
      .def("set_value", &NumericValueWidget::SetValue)
      .def("get_min_value", &NumericValueWidget::GetMinValue)
      .def("set_min_value", &NumericValueWidget::SetMinValue)
      .def("get_max_value", &NumericValueWidget::GetMaxValue)
      .def("set_max_value", &NumericValueWidget::SetMaxValue);

  // VirtualButtonWidget
  py::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(
      module, "VirtualButtonWidget")
      .def(py::init());

  // VirtualMenuItemWidget
  py::class_<VirtualMenuItemWidget, VirtualWidget, std::shared_ptr<VirtualMenuItemWidget>>(
      module, "VirtualMenuItemWidget")
      .def(py::init());

  // VirtualMenuWidget
  py::class_<VirtualMenuWidget, VirtualWidget, std::shared_ptr<VirtualMenuWidget>>(
      module, "VirtualMenuWidget")
      .def(py::init());

  // VirtualProgressBarWidget
  py::class_<VirtualProgressBarWidget, NumericValueWidget,
             std::shared_ptr<VirtualProgressBarWidget>>(module, "VirtualProgressBarWidget")
      .def(py::init())
      .def("get_orientation", &VirtualProgressBarWidget::GetOrientation)
      .def("set_orientation", &VirtualProgressBarWidget::SetOrientation);

  // VirtualScrollBarWidget
  py::class_<VirtualScrollbarWidget, NumericValueWidget, std::shared_ptr<VirtualScrollbarWidget>>(
      module, "VirtualScrollbarWidget")
      .def(py::init())
      .def("get_orientation", &VirtualScrollbarWidget::GetOrientation)
      .def("set_orientation", &VirtualScrollbarWidget::SetOrientation);

  // VirtualSliderWidget
  py::class_<VirtualSliderWidget, NumericValueWidget, std::shared_ptr<VirtualSliderWidget>>(
      module, "VirtualSliderWidget")
      .def(py::init())
      .def("get_orientation", &VirtualSliderWidget::GetOrientation)
      .def("set_orientation", &VirtualSliderWidget::SetOrientation);

  // VirtualSpinnerWidget
  py::class_<VirtualSpinnerWidget, NumericValueWidget, std::shared_ptr<VirtualSpinnerWidget>>(
      module, "VirtualSpinnerWidget")
      .def(py::init());

  // VirtualTextInputWidget
  py::class_<VirtualTextInputWidget, VirtualWidget, std::shared_ptr<VirtualTextInputWidget>>(
      module, "VirtualTextInputWidget")
      .def(py::init())
      .def("get_selected_text", &VirtualTextInputWidget::GetSelectedText)
      .def("set_selected_text", &VirtualTextInputWidget::SetSelectedText)
      .def("get_insertion_point", &VirtualTextInputWidget::GetInsertionPoint)
      .def("set_insertion_point", &VirtualTextInputWidget::SetInsertionPoint)
      .def("is_text_field", &VirtualTextInputWidget::IsTextField)
      .def("set_is_text_field", &VirtualTextInputWidget::SetIsTextField);

  // VirtualTextWidget
  py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(
      module, "VirtualTextWidget")
      .def(py::init())
      .def("get_selected_text", &VirtualTextWidget::GetSelectedText)
      .def("set_selected_text", &VirtualTextWidget::SetSelectedText);

  // VirtualUnknownWidget
  py::class_<VirtualUnknownWidget, VirtualWidget,
             std::shared_ptr<VirtualUnknownWidget>>(module, "VirtualUnknownWidget")
      .def(py::init());

  // VirtualWindowWidget
  py::class_<VirtualWindowWidget, VirtualWidget, std::shared_ptr<VirtualWindowWidget>>(
      module, "VirtualWindowWidget")
      .def(py::init())
      .def("is_modal", &VirtualWindowWidget::IsModal)
      .def("set_is_modal", &VirtualWindowWidget::SetIsModal);
}

/**
 * Bind all screen reader APIs
 *
 * @param module python module object
 */
void BindScreenReader(py::module_& module) {
  py::class_<ScreenReader>(module, "ScreenReader")
      .def(py::init())
      .def("get_virtual_widget_tree_by_pid",
           &ScreenReader::GetVirtualWidgetTreeByPID,
           py::return_value_policy::take_ownership);
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