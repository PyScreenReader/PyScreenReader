load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")

package(default_visibility = ["//visibility:public"])

# Compiles C++ native code to .so/.pyd files
pybind_extension(
    name = "PyScreenReader",
    srcs = [
        "//src:bindings.cpp",
        "//src/api:screen_reader.cpp",
    ],
    deps = [
        "//src:bindings_registry",
        "//src/api:screen_reader",
        "//src/vwidget:vwidget_bind",
    ],
)
