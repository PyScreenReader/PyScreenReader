package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

pybind_library(
    name = "virtual_container_widget",
    hdrs = ["//include/vwidget:virtual_container_widget.h"],
    srcs = [":virtual_container_widget.cpp"],
    deps = [
        "//src:bindings_registry",
        ":virtual_widget"
    ]
)

pybind_library(
    name = "virtual_widget",
    hdrs = ["//include/vwidget:virtual_widget.h"],
    srcs = [":virtual_widget.cpp"],
    deps = [
        "//src:bindings_registry",
    ]
)

pybind_library(
    name = "vwidget_bind",
    deps = [
        "//src/vwidget:virtual_container_widget",
        "//src/vwidget:virtual_widget",
        "//src/vwidget/widgets:virtual_components"
    ],
)
