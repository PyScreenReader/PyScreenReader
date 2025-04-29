package(default_visibility = ["//visibility:public"])
load("@rules_python//python:py_library.bzl", "py_library")
load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")

compile_pip_requirements(
    name = "requirements",
    src = "//tests/py:requirements.in",
    requirements_txt = "//tests/py:requirements_lock.txt",
)

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