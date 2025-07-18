package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "atspi_utils",
    hdrs = [
        ":atspi_utils.h",
    ],
    srcs = [
        ":atspi_utils.cpp",
    ],
    deps = [
        "@glib//:lib",
        "@atspi//:lib",
    ]
)

