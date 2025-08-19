load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

package(default_visibility = ["//visibility:public"])

pybind_library(
    name = "bindings",
    srcs = [":bindings.cpp"],
    deps = [
        "//src/api:screen_reader",
        "//src/vwidget:all_virtual_widgets",
    ],
)
