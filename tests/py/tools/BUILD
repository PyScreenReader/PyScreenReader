package(default_visibility = ["//visibility:public"])
load("@rules_python//python:py_library.bzl", "py_library")
load("@pytest_env//:requirements.bzl", "requirement")

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
        "utils.py",
    ],
    data = [
        "//:PyScreenReader",
        requirement("pytest"),
    ]
)