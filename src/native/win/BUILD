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
        "comsuppw.lib",
    ],
    deps = [
        ":vwidget_generator_win",
    ],
)

pybind_library(
    name = "vwidget_factory",
    srcs = [
        ":vwidget_factory_win.cpp",
    ],
    hdrs = [
        ":vwidget_factory_win.h",
    ],
    linkopts = [
        "ole32.lib",
        "oleaut32.lib",
        "comsuppw.lib",
        "comsuppw.lib",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
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
        "//src/native/win:vwidget_factory",
        "//src/vwidget/widgets:virtual_components",
    ],
)
