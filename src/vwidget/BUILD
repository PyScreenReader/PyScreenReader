load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "virtual_widget",
    srcs = [":virtual_widget.cpp"],
    hdrs = ["//include/vwidget:virtual_widget.h"],
)

pybind_library(
    name = "numeric_value_widget",
    srcs = [":numeric_value_widget.cpp"],
    hdrs = ["//include/vwidget:numeric_value_widget.h"],
    deps = [
        "//src/vwidget:virtual_widget",
    ],
)

pybind_library(
    name = "all_virtual_widgets",
    deps = [
        "//src/vwidget:numeric_value_widget",
        "//src/vwidget:virtual_widget",
        "//src/vwidget/widgets:virtual_components",
    ],
)
