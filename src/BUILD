package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "bindings",
    srcs = [":bindings.cpp"],
    deps = [
        "//src/vwidget:all_virtual_widgets",
        "//src/api:screen_reader",
    ],
)
