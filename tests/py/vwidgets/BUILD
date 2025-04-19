package(default_visibility = ["//visibility:public"])
load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("//tests/py:tools/pytest_defs.bzl", "pytest_test")

pytest_test(
    name = "test_inheritance",
    srcs = ["test_inheritance.py"]
)

pytest_test(
    name = "test_virtual_button_widget",
    srcs = ["test_virtual_button_widget.py"],
    deps = ["//tests/py:test_utils"],
)

pytest_test(
    name = "test_virtual_container",
    srcs = ["test_virtual_container.py"],
)

pytest_test(
    name = "test_virtual_widget",
    srcs = ["test_virtual_widget.py"]
)



