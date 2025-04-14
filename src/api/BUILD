package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")

pybind_library(
    name = "screen_reader",
    hdrs = ["//include/api:screen_reader.h"],
    srcs = [":screen_reader.cpp"],
    deps = [
        "//src:bindings_registry",
        "//src/vwidget:vwidget_bind",
        "//src/native/win:screen_reader_impl_win",
    ],
)

pybind_library(
    name = "screen_reader_bind",
    deps = [
        "//src/api:screen_reader",
    ],
)
# Main extension entrypoint - accessed via 'py_screen_reader' module
pybind_extension(
    name = "py_screen_reader_lib",
    deps = [
        "//src/vwidget:vwidget_bind",
        "//src/api:screen_reader_bind",
    ],
)

py_library(
    name = "py_screen_reader",
    data = [":py_screen_reader_lib"],
    imports = ["."],
)