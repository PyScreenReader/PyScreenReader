package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "screen_reader_impl_win",
    hdrs = [
        ":screen_reader_impl_win.h",
    ],
    srcs = [
        ":screen_reader_impl_win.cpp",
    ],
    deps = [
        ":vwidget_generator_win"
    ],
)

pybind_library(
    name = "vwidget_generator_win",
    hdrs = [
        ":vwidget_generator_win.h",
    ],
    srcs = [
        ":vwidget_generator_win.cpp",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components"
    ],
)
