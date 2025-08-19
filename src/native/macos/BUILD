load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "screen_reader_impl_mac",
    srcs = [
        ":screen_reader_impl_mac.cpp",
    ],
    hdrs = [
        ":screen_reader_impl_mac.h",
    ],
    linkopts = ["-framework ApplicationServices"],
    deps = [
        "//src/native/macos:vwidget_generator",
        "//src/native/macos/utils:cf_utils",
        "//src/native/macos/utils:system_utils",
        "//src/vwidget/widgets:virtual_components",
    ],
)

pybind_library(
    name = "vwidget_generator",
    srcs = [
        ":vwidget_generator_mac.cpp",
    ],
    hdrs = [
        ":vwidget_generator_mac.h",
    ],
    linkopts = ["-framework ApplicationServices"],
    deps = [
        ":vwidget_factory",
        "//src/native/macos/utils:cf_utils",
        "//src/vwidget/widgets:virtual_components",
    ],
)

pybind_library(
    name = "vwidget_factory",
    srcs = [
        ":vwidget_factory_mac.cpp",
    ],
    hdrs = [
        ":vwidget_factory_mac.h",
    ],
    linkopts = ["-framework ApplicationServices"],
    deps = [
        "//src/native/macos/utils:cf_utils",
        "//src/vwidget/widgets:virtual_components",
    ],
)
