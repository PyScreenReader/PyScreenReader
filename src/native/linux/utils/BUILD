load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "atspi_utils",
    srcs = [
        ":atspi_utils.cpp",
    ],
    hdrs = [
        ":atspi_utils.h",
    ],
    deps = [
        "@atspi//:lib",
        "@glib//:lib",
    ],
)
