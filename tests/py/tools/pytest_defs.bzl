load("@rules_python//python:defs.bzl", "py_test")
load("@pytest_env//:requirements.bzl", "requirement")

def pytest_test(name, srcs, deps=[], args=[], data=[], **kwargs):
    """
    Build a pytest target
    This function wrapper the original py_test target

    :param name: test target name
    :param deps: additional dependencies to include (pytest is already implicitly injected)
    :params args: args to pass to pytest
    :param data: additional data to to include (PyScreenReader is already implicitly injected)
    :param **kwargs: additional args to pass to original py_test target
    """
    py_test(
        name = name,
        srcs = ["//tests/py/tools:pytest_wrapper.py"] + srcs,
        main = "//tests/py/tools:pytest_wrapper.py",
        args = ["--capture=no"] + args + ["$(location :%s)" % x for x in srcs],
        deps = deps + [requirement("pytest")],
        data = data + ["//:PyScreenReader"],
        imports = ["."],
        **kwargs
    )

def pytest_suite(test_files, deps = []):
    """
    Build a suite of test cases for each python test file

    :param test_files: a collection of the
    :param deps: additional dependencies to include (pytest and PyScreenReader are already implicitly injected)
    """
    for test_file in test_files:
        test_name = test_file.split("/")[-1].replace(".py", "")
        pytest_test(
            name = test_name,
            srcs = [test_file],
            deps = deps
        )