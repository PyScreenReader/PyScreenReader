load("@rules_python//python:defs.bzl", "py_test")
load("@pytest_deps//:requirements.bzl", "requirement")

def pytest_test(name, srcs, deps=[], args=[], data=[], **kwargs):
    py_test(
        name = name,
        srcs = ["//tests/py:tools/pytest_wrapper.py"] + srcs,
        main = "//tests/py:tools/pytest_wrapper.py",
        args = ["--capture=no"] + args + ["$(location :%s)" % x for x in srcs],
        deps = deps + [requirement("pytest")],
        data = data + ["//:PyScreenReader"],
        **kwargs
    )