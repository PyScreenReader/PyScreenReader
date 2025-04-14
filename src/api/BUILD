package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")
load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

string_flag(
    name = "os",
    build_setting_default = "win",
)

config_setting(
    name = "mac_build",
    flag_values = {":os" : "mac",},
)

config_setting(
    name = "win_build",
    flag_values = {":os": "win",},
)

# Select the correct platform
pybind_library(
    name = "screen_reader_impl",
    srcs = select({
       ":mac_build": ["//src/native/macos:screen_reader_impl_mac"],
       ":win_build": ["//src/native/win:screen_reader_impl_win"],
       "//conditions:default": [],
   })
)

pybind_library(
    name = "screen_reader",
    hdrs = ["//include/api:screen_reader.h"],
    srcs = [":screen_reader.cpp"],
    deps = [
        "//src:bindings_registry",
        "//src/vwidget:vwidget_bind",
        ":screen_reader_impl",
    ],
)

pybind_library(
    name = "screen_reader_bind",
    deps = [
        "//src/api:screen_reader",
    ],
)
# Compiles C++ native code to .so files
pybind_extension(
    name = "py_screen_reader_lib",
    deps = [
        "//src/vwidget:vwidget_bind",
        "//src/api:screen_reader_bind",
    ],
)

# This transforms our shared libs into an importable python module
py_library(
    name = "py_screen_reader",
    data = [":py_screen_reader_lib"],
    imports = ["."],
)