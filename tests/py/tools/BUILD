package(default_visibility = ["//visibility:public"])
load("@rules_python//python:py_library.bzl", "py_library")
load("@pytest_env//:requirements.bzl", "requirement")

py_library(
    name = "pytest_constants",
    srcs = [
        "constants.py",
    ],
)

py_library(
    name = "pytest_wrapper",
    srcs = [
        "pytest_wrapper.py"
    ],
    deps = [
        requirement("pytest"),
    ]
)

py_library(
    name = "test_utils",
    srcs = [
        "test_utils.py",
    ],
    deps = [
        "pytest_constants",
        requirement("pytest"),
    ],
    data = [
        "//:PyScreenReader",
    ]
)

py_library(
    name = "e2e_test_case_process",
    srcs = [
        "e2e_test_case_process.py"
    ],
    deps = [
        "@bazel_tools//tools/python/runfiles",
        "//tools:tools_helper"
    ]
)