#include "bindings_registry.h"

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/numeric_value_widget.h"

#include "include/vwidget/widgets/virtual_button_widget.h"
#include "include/vwidget/widgets/virtual_menu_item_widget.h"
#include "include/vwidget/widgets/virtual_menu_widget.h"
#include "include/vwidget/widgets/virtual_progress_bar_widget.h"
#include "include/vwidget/widgets/virtual_scroll_bar_widget.h"
#include "include/vwidget/widgets/virtual_slider_widget.h"
#include "include/vwidget/widgets/virtual_spinner_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"
#include "include/vwidget/widgets/virtual_unknown_widget.h"
#include "include/vwidget/widgets/virtual_window_widget.h"

#include "include/api/screen_reader.h"

namespace bindings {
namespace py = pybind11;

void BindVirtualWidgets(py::module_& module) {
  py::class_<VirtualWidget, std::shared_ptr<VirtualWidget>>(module, "VirtualWidget")
      .def("get_title_text", &VirtualWidget::GetTitleText)
      .def("get_help_text", &VirtualWidget::GetHelpText)
      .def("get_native_name", &VirtualWidget::GetNativeName)
      .def("get_x", &VirtualWidget::GetX)
      .def("get_y", &VirtualWidget::GetY)
      .def("get_width", &VirtualWidget::GetWidth)
      .def("get_height", &VirtualWidget::GetHeight)
      .def("is_visible", &VirtualWidget::IsVisible)
      .def("is_focused", &VirtualWidget::IsFocused)
      .def("get_parent", &VirtualWidget::GetParent)
      .def("get_child", &VirtualWidget::GetChild)
      .def("get_widget_name", &VirtualWidget::GetWidgetName);

  py::class_<NumericValueWidget, VirtualWidget,
                   std::shared_ptr<NumericValueWidget>>(module, "NumericValueWidget")
      .def("get_value", &NumericValueWidget::GetValue)
      .def("get_min_value", &NumericValueWidget::GetMinValue)
      .def("get_max_value", &NumericValueWidget::GetMaxValue);

  py::class_<VirtualButtonWidget, VirtualWidget, std::shared_ptr<VirtualButtonWidget>>(
      module, "VirtualButtonWidget")
      .def(py::init());

  py::class_<VirtualMenuItemWidget, VirtualWidget, std::shared_ptr<VirtualMenuItemWidget>>(
      module, "VirtualMenuItemWidget");

  py::class_<VirtualMenuWidget, VirtualWidget, std::shared_ptr<VirtualMenuWidget>>(
      module, "VirtualMenuWidget")
      .def(py::init());

  py::class_<VirtualProgressBarWidget, NumericValueWidget,
             std::shared_ptr<VirtualProgressBarWidget>>(module, "VirtualProgressBarWidget")
      .def(py::init())
      .def("get_orientation", &VirtualProgressBarWidget::GetOrientation);

  py::class_<VirtualScrollbarWidget, NumericValueWidget, std::shared_ptr<VirtualScrollbarWidget>>(
      module, "VirtualScrollbarWidget")
      .def(py::init())
      .def("get_orientation", &VirtualScrollbarWidget::GetOrientation);

  py::class_<VirtualSliderWidget, NumericValueWidget, std::shared_ptr<VirtualSliderWidget>>(
      module, "VirtualSliderWidget")
      .def(py::init())
      .def("get_orientation", &VirtualSliderWidget::GetOrientation);

  py::class_<VirtualSpinnerWidget, NumericValueWidget, std::shared_ptr<VirtualSpinnerWidget>>(
      module, "VirtualSpinnerWidget")
      .def(py::init());

  py::class_<VirtualTextInputWidget, VirtualWidget, std::shared_ptr<VirtualTextInputWidget>>(
      module, "VirtualTextInputWidget")
      .def(py::init())
      .def("get_selected_text", &VirtualTextInputWidget::GetSelectedText)
      .def("get_insertion_point", &VirtualTextInputWidget::GetInsertionPoint)
      .def("is_text_field", &VirtualTextInputWidget::IsTextField);

  py::class_<VirtualTextWidget, VirtualWidget, std::shared_ptr<VirtualTextWidget>>(
      module, "VirtualTextWidget")
      .def(py::init())
      .def("get_selected_text", &VirtualTextWidget::GetSelectedText);

  py::class_<VirtualUnknownWidget,
             std::shared_ptr<VirtualUnknownWidget>>(module, "VirtualUnknownWidget")
      .def(py::init());

  py::class_<VirtualWindowWidget, VirtualWidget, std::shared_ptr<VirtualWindowWidget>>(
      module, "VirtualWindowWidget")
      .def(py::init())
      .def("is_modal", &VirtualWindowWidget::IsModal);
}


void BindScreenReader(py::module_& module) {
  py::class_<ScreenReader>(module, "ScreenReader")
      .def(py::init())
      .def("getVirtualWidgetTreeByPID",
           &ScreenReader::GetVirtualWidgetTreeByPID,
           py::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByTitle",
           &ScreenReader::GetVirtualWidgetTreeByTitle,
           py::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByClassName",
           &ScreenReader::GetVirtualWidgetTreeByClassName,
           py::return_value_policy::take_ownership);
}

}  // namespace bindings

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