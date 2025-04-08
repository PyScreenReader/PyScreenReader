package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

pybind_library(
    name = "vwidget",
    srcs = [
    ],
    deps = [
        "virtual_button_widget",
        "virtual_menu_group_widget",
        "virtual_menu_item_widget",
        "virtual_root_widget",
        "virtual_text_field_widget",
        "virtual_text_widget",
    ],
)

cc_library(
    name = "virtual_button_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_button_widget.h",
    ],
    srcs = [
       ":virtual_button_widget.cpp",
    ]
)

cc_library(
    name = "virtual_menu_group_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_menu_group_widget.h",
    ],
    srcs = [
        ":virtual_menu_group_widget.cpp",
    ]
)

cc_library(
    name = "virtual_menu_item_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_menu_item_widget.h",
    ],
    srcs = [
        ":virtual_menu_item_widget.cpp",
    ]
)

cc_library(
    name = "virtual_root_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_root_widget.h",
    ],
    srcs = [
        ":virtual_root_widget.cpp",
    ]
)

cc_library(
    name = "virtual_text_field_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_text_field_widget.h",
    ],
    srcs = [
        ":virtual_text_field_widget.cpp",
    ]
)

cc_library(
    name = "virtual_text_widget",
    hdrs = [
        "//include/vwidget/widgets:virtual_text_widget.h",
    ],
    srcs = [
        ":virtual_text_widget.cpp",
    ]
)