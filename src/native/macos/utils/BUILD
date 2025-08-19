load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "cf_utils",
    srcs = [
        ":cf_utils.cpp",
    ],
    hdrs = [
        ":cf_utils.h",
    ],
)

pybind_library(
    name = "system_utils",
    srcs = [
        ":system_utils.cpp",
    ],
    hdrs = [
        ":system_utils.h",
    ],
)
