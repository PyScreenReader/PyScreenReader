package(default_visibility = ["//visibility:public"])
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_library.bzl", "py_library")
load("//tests/py/tools:pytest_defs.bzl", "pytest_test")
load("@pytest_deps//:requirements.bzl", "requirement")

compile_pip_requirements(
    name = "requirements",
    src = "//tests/py:requirements.in",
    requirements_txt = "//tests/py:requirements_lock.txt",
)

pytest_test(
    name = "test_screen_reader",
    srcs = ["test_screen_reader.py"],
)