package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "screen_reader_impl_mac",
    hdrs = [
        ":screen_reader_impl_mac.h",
    ],
    srcs = [
        ":screen_reader_impl_mac.cpp",
    ],
    deps = [
        "//src/native/macos/utils:utils",
        "//src/vwidget/widgets:virtual_components",
        "//src/native/macos:vwidget_generator",
    ],
    linkopts = ["-framework ApplicationServices"],
)

pybind_library(
    name = "vwidget_generator",
    hdrs = [
        ":vwidget_generator.h",
    ],
    srcs = [
        ":vwidget_generator.cpp",
    ],
    deps = [
        "//src/native/macos/utils:utils",
        "//src/vwidget/widgets:virtual_components"
    ],
    linkopts = ["-framework ApplicationServices"],
)
