package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

cc_library(
    name = "virtual_container_widget",
    srcs = ["//include/vwidget:virtual_container_widget.h"],
    deps = [":virtual_container_widget.cpp"],
)

cc_library(
    name = "virtual_widget",
    srcs = ["//include/vwidget:virtual_widget.h"],
    deps = [":virtual_widget.cpp"],
)

pybind_library(
    name = "vwidget_bind",
    deps = [
        "//src/vwidget:virtual_container_widget",
        "//src/vwidget:virtual_widget",
        "//src/vwidget/widgets:virtual_button_widget",
        "//src/vwidget/widgets:virtual_menu_group_widget",
        "//src/vwidget/widgets:virtual_menu_item_widget",
        "//src/vwidget/widgets:virtual_root_widget",
        "//src/vwidget/widgets:virtual_text_field_widget",
        "//src/vwidget/widgets:virtual_text_widget",
    ],
)
