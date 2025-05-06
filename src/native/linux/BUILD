package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "screen_reader_impl_linux",
    hdrs = [
        ":screen_reader_impl_linux.h",
    ],
    srcs = [
        ":screen_reader_impl_linux.cpp",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
    ],
)