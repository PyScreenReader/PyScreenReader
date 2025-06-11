package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

pybind_library(
    name = "virtual_widget",
    hdrs = ["//include/vwidget:virtual_widget.h"],
    srcs = [":virtual_widget.cpp"],
    deps = ["//src/base:build_flags"]
)

pybind_library(
    name = "numeric_value_widget",
    hdrs = ["//include/vwidget:numeric_value_widget.h"],
    srcs = [":numeric_value_widget.cpp"],
    deps = [
        "//src/vwidget:virtual_widget",
    ]
)

pybind_library(
    name = "all_virtual_widgets",
    deps = [
        "//src/vwidget:virtual_widget",
        "//src/vwidget:numeric_value_widget",
        "//src/vwidget/widgets:virtual_components",
    ],
)
