load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "virtual_components",
    srcs = glob(["*.cpp"]),
    hdrs = [
        "//include/vwidget:orientation.h",
        "//include/vwidget/widgets:virtual_button_widget.h",
        "//include/vwidget/widgets:virtual_group_widget.h",
        "//include/vwidget/widgets:virtual_menu_item_widget.h",
        "//include/vwidget/widgets:virtual_menu_widget.h",
        "//include/vwidget/widgets:virtual_progress_bar_widget.h",
        "//include/vwidget/widgets:virtual_scrollbar_widget.h",
        "//include/vwidget/widgets:virtual_slider_widget.h",
        "//include/vwidget/widgets:virtual_spinner_widget.h",
        "//include/vwidget/widgets:virtual_text_input_widget.h",
        "//include/vwidget/widgets:virtual_text_widget.h",
        "//include/vwidget/widgets:virtual_unknown_widget.h",
        "//include/vwidget/widgets:virtual_window_widget.h",
    ],
    deps = [
        "//src/vwidget:numeric_value_widget",
        "//src/vwidget:virtual_widget",
    ],
)
