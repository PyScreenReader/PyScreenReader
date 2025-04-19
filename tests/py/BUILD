package(default_visibility = ["//visibility:public"])
load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_library.bzl", "py_library")
load("//tests/py:tools/pytest_defs.bzl", "pytest_test")

compile_pip_requirements(
    name = "requirements",
    src = "//tests/py:requirements.in",
    requirements_txt = "//tests/py:requirements_lock.txt",
)

py_library(
    name = "pytest_constants",
    srcs = [
        "//tests/py:constants.py",
    ],
)

py_library(
    name = "test_utils",
    srcs = [
        "//tests/py:test_utils.py",
    ],
    deps = [
        "//tests/py:pytest_constants",
        requirement("pytest"),
    ],
    data = [
        "//:PyScreenReader",
    ]
)

pytest_test(
    name = "test_screen_reader",
    srcs = ["test_screen_reader.py"],
)
