package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "cf_utils",
    hdrs = [
        ":cf_utils.h",
    ],
    srcs = [
        ":cf_utils.cpp",
    ],
)

pybind_library(
    name = "system_utils",
    hdrs = [
        ":system_utils.h",
    ],
    srcs = [
        ":system_utils.cpp",
    ],
)
