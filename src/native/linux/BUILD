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
        "//src/native/linux:vwidget_generator_linux",
        "//src/native/linux/utils:atspi_utils",
        "@glib//:lib",
        "@atspi//:lib",
    ],
)

pybind_library(
    name = "vwidget_generator_linux",
    hdrs = [
        ":vwidget_generator_linux.h",
    ],
    srcs = [
        ":vwidget_generator_linux.cpp",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
        "//src/native/linux:vwidget_factory_linux",
        "//src/native/linux/utils:atspi_utils",
        "@glib//:lib",
        "@atspi//:lib",
    ],
)

pybind_library(
    name = "vwidget_factory_linux",
    hdrs = [
        ":vwidget_factory_linux.h",
    ],
    srcs = [
        ":vwidget_factory_linux.cpp",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
        "//src/native/linux/utils:atspi_utils",
        "@glib//:lib",
        "@atspi//:lib",
    ],
)

