package(default_visibility = ["//visibility:public"])
load("@rules_python//python:py_library.bzl", "py_library")
load("@pytest_deps//:requirements.bzl", "requirement")

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