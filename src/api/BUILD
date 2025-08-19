load("@bazel_skylib//rules:common_settings.bzl", "string_flag")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "screen_reader",
    srcs = [":screen_reader.cpp"],
    hdrs = ["//include/api:screen_reader.h"],
    deps = [
        "//src/base:build_flags",
        "//src/vwidget:all_virtual_widgets",
    ] + select({
        "@platforms//os:macos": ["//src/native/macos:screen_reader_impl_mac"],
        "@platforms//os:windows": ["//src/native/win:screen_reader_impl_win"],
        "@platforms//os:linux": ["//src/native/linux:screen_reader_impl_linux"],
        "//conditions:default": [],
    }),
)
