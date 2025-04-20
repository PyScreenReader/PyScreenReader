package(default_visibility = ["//visibility:public"])

load("@pybind11_bazel//:build_defs.bzl", "pybind_library")

pybind_library(
    name = "bindings_registry",
    hdrs = [":bindings_registry.h"],
    srcs = [":bindings_registry.cpp"],
)
pybind_library(
    name = "bindings",
    srcs = [":bindings.cpp"],
    deps = [":bindings_registry"],
)