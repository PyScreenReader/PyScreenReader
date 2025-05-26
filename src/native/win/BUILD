load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "screen_reader_impl_win",
    srcs = [
        ":screen_reader_impl_win.cpp",
    ],
    hdrs = [
        ":screen_reader_impl_win.h",
    ],
    linkopts = [
        "ole32.lib",
        "oleaut32.lib",
        "comsuppw.lib",
    ],
    deps = [
        ":vwidget_generator_win",
    ],
)

pybind_library(
    name = "vwidget_generator_win",
    srcs = [
        ":vwidget_generator_win.cpp",
    ],
    hdrs = [
        ":vwidget_generator_win.h",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
    ],
)
