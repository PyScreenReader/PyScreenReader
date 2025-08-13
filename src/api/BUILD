package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

pybind_library(
    name = "screen_reader",
    hdrs = ["//include/api:screen_reader.h"],
    srcs = [":screen_reader.cpp"],
    deps = [
        "//src/vwidget:all_virtual_widgets",
        "//src/base:build_flags"
    ] +
    select({
       "@platforms//os:macos": ["//src/native/macos:screen_reader_impl_mac"],
       "@platforms//os:windows": ["//src/native/win:screen_reader_impl_win"],
       "@platforms//os:linux": ["//src/native/linux:screen_reader_impl_linux"],
       "//conditions:default": [],
   }),
)

