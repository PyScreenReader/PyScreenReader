package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "virtual_components",
    hdrs = [
        "//include/vwidget/widgets:virtual_button_widget.h",
        "//include/vwidget/widgets:virtual_menu_group_widget.h",
        "//include/vwidget/widgets:virtual_menu_item_widget.h",
        "//include/vwidget/widgets:virtual_root_widget.h",
        "//include/vwidget/widgets:virtual_text_field_widget.h",
        "//include/vwidget/widgets:virtual_text_widget.h",
    ],
    srcs = [
        "//src/vwidget/widgets:virtual_button_widget.cpp",
        "//src/vwidget/widgets:virtual_menu_group_widget.cpp",
        "//src/vwidget/widgets:virtual_menu_item_widget.cpp",
        "//src/vwidget/widgets:virtual_root_widget.cpp",
        "//src/vwidget/widgets:virtual_text_field_widget.cpp",
        "//src/vwidget/widgets:virtual_text_widget.cpp",
    ],
)