package(default_visibility = ["//visibility:public"])

load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@py_tests_deps//:requirements.bzl", "requirement")

compile_pip_requirements(
    name = "requirements",
    src = "requirements.in",
    requirements_txt = "requirements_lock.txt",
)