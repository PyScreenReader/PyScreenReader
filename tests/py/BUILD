load("@pytest_env//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_library.bzl", "py_library")
load("//tests/py/tools:pytest_defs.bzl", "pytest_test")

package(default_visibility = ["//visibility:public"])

compile_pip_requirements(
    name = "requirements",
    src = "//tests/py:requirements.in",
    requirements_txt = "//tests/py:requirements_lock.txt",
    requirements_windows = "//tests/py:requirements_win_lock.txt",
)

pytest_test(
    name = "test_screen_reader",
    srcs = ["test_screen_reader.py"],
)
