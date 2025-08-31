load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "system_utils",
    srcs = [":system_utils.cpp"],
    hdrs = [":system_utils.h"],
    linkopts = [
        "ole32.lib",
        "oleaut32.lib",
        "comsuppw.lib",
        "comsuppw.lib",
    ],
    deps = [
        "//src/native/win/utils:pattern_data",
        "//src/vwidget:all_virtual_widgets",
    ],
)

pybind_library(
    name = "pattern_data",
    srcs = [":pattern_data.cpp"],
    hdrs = [":pattern_data.h"],
)
