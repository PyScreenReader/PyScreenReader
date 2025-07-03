package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "screen_reader_impl_linux",
    hdrs = [
        ":screen_reader_impl_linux.h",
    ],
    srcs = [
        ":screen_reader_impl_linux.cpp",
    ], # I needed to install some packages to get this working, I don't know how to automatically include it in bazel, so I'm just going to do this forcibly
    # sudo apt-get install libatk-bridge2.0-0 at-spi2-core at-spi2-atk libatspi2.0-dev libglib2.0-dev
    linkopts = [
        "-latspi",
        "-ldbus-1",
        "-lglib-2.0",
        "-lgobject-2.0",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
#         "//src/native/linux:vwidget_generator",
    ],
)

pybind_library(
    name = "vwidget_generator",
    hdrs = [
        ":vwidget_generator.h",
    ],
    srcs = [
        ":vwidget_generator.cpp",
    ],
    linkopts = [
        "-latspi",
        "-ldbus-1",
        "-lglib-2.0",
    ],
    deps = [
        "//src/vwidget/widgets:virtual_components",
    ],
)
