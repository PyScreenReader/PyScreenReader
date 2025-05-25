package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "virtual_components",
    hdrs = [
        "//include/vwidget:orientation.h",
        "//include/vwidget/widgets:virtual_button_widget.h",
        "//include/vwidget/widgets:virtual_menu_item_widget.h",
        "//include/vwidget/widgets:virtual_menu_widget.h",
        "//include/vwidget/widgets:virtual_text_input_widget.h",
        "//include/vwidget/widgets:virtual_text_widget.h",
        "//include/vwidget/widgets:virtual_unknown_widget.h",
        "//include/vwidget/widgets:virtual_window_widget.h",
        "//include/vwidget/widgets:virtual_scrollbar_widget.h",
        "//include/vwidget/widgets:virtual_slider_widget.h",
        "//include/vwidget/widgets:virtual_progress_bar_widget.h",
        "//include/vwidget/widgets:virtual_spinner_widget.h",
        "//include/vwidget/widgets:virtual_group_widget.h",
    ],
    srcs = glob(["*.cpp"]),
    deps = [
        "//src/vwidget:virtual_widget",
        "//src/vwidget:numeric_value_widget",
    ],
)
