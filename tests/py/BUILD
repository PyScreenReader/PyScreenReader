package(default_visibility = ["//visibility:public"])
load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_test.bzl", "py_test")
load("@rules_python//python:py_library.bzl", "py_library")

compile_pip_requirements(
    name = "requirements",
    src = "requirements.in",
    requirements_txt = "requirements_lock.txt",
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
)

# Attach the so/pyd bindings as data
py_test(
    name = "test_screen_reader",
    srcs = ["//tests/py:test_screen_reader.py"],
    deps = [
        requirement("pytest"),
    ],
    data = [
        "//:PyScreenReader",
    ]
)
