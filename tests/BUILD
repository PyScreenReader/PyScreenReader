load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_test.bzl", "py_test")

package(default_visibility = ["//visibility:public"])

compile_pip_requirements(
    name = "requirements",
    src = "//tests/py:requirements.in",
    requirements_txt = "//tests/py:requirements_lock.txt",
)

#py_test(
#    name = "test_screen_reader",
#    srcs = ["//tests/py:test_screen_reader.py"],
#    deps = ["//src/api:py_screen_reader"],
#    requirement("pytest"),
#)
