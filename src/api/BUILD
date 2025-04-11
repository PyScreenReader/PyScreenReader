package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

cc_library(
    name = "screen_reader",
    hdrs = ["//include/api:screen_reader.h"],
    srcs = [":screen_reader.cpp"],
    deps = ["//src:bindings_registry"],
)

pybind_library(
    name = "screen_reader_bind",
    deps = [
        "//src/api:screen_reader",
    ],
)
# Main extension entrypoint - accessed via 'py_screen_reader' module
pybind_extension(
    name = "py_screen_reader",
    deps = [
        "//src/vwidget:vwidget_bind",
        "//src/api:screen_reader_bind",
    ],
)