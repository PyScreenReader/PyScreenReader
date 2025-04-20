package(default_visibility = ["//visibility:public"])
load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "utils",
    hdrs = [
        ":attribute_utils.h",
        ":system_utils.h",
    ],
    srcs = [
        ":attribute_utils.cpp",
        ":system_utils.cpp",
    ],
)
