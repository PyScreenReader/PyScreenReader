load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "screen_reader_impl_linux",
    srcs = [
        ":screen_reader_impl_linux.cpp",
    ],
    hdrs = [
        ":screen_reader_impl_linux.h",
    ],
    deps = [
        "//src/native/linux:vwidget_generator_linux",
        "//src/native/linux/utils:atspi_utils",
        "//src/vwidget/widgets:virtual_components",
        "@atspi//:lib",
        "@glib//:lib",
    ],
)

pybind_library(
    name = "vwidget_generator_linux",
    srcs = [
        ":vwidget_generator_linux.cpp",
    ],
    hdrs = [
        ":vwidget_generator_linux.h",
    ],
    deps = [
        "//src/native/linux:vwidget_factory_linux",
        "//src/native/linux/utils:atspi_utils",
        "//src/vwidget/widgets:virtual_components",
        "@atspi//:lib",
        "@glib//:lib",
    ],
)

pybind_library(
    name = "vwidget_factory_linux",
    srcs = [
        ":vwidget_factory_linux.cpp",
    ],
    hdrs = [
        ":vwidget_factory_linux.h",
    ],
    deps = [
        "//src/native/linux/utils:atspi_utils",
        "//src/vwidget/widgets:virtual_components",
        "@atspi//:lib",
        "@glib//:lib",
    ],
)
