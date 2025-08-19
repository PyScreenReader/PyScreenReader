load("@pytest_env//:requirements.bzl", "requirement")
load("@rules_python//python:py_library.bzl", "py_library")

package(default_visibility = ["//visibility:public"])

py_library(
    name = "pytest_wrapper",
    srcs = [
        "pytest_wrapper.py",
    ],
    deps = [
        requirement("pytest"),
    ],
)

py_library(
    name = "test_utils",
    srcs = [
        "utils.py",
    ],
    data = [
        "//:PyScreenReader",
        requirement("pytest"),
    ],
)
