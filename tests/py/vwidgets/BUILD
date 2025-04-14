package(default_visibility = ["//visibility:public"])
load("@pytest_deps//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_test.bzl", "py_test")

compile_pip_requirements(
    name = "requirements",
    src = "requirements.in",
    requirements_txt = "requirements_lock.txt",
)

py_test(
    name = "test_inheritance",
    srcs = ["//tests/py/vwidgets:test_inheritance.py"],
    deps = [
        "//src/api:py_screen_reader",
        requirement("pytest"),
    ],
)

py_test(
    name = "test_virtual_button_widget",
    srcs = ["//tests/py/vwidgets:test_virtual_button_widget.py"],
    deps = [
        "//src/api:py_screen_reader",
        "//tests/py:test_utils",
        requirement("pytest"),
    ],
)

py_test(
    name = "test_virtual_container",
    srcs = ["//tests/py/vwidgets:test_virtual_container.py"],
    deps = [
        "//src/api:py_screen_reader",
        requirement("pytest"),
    ],
)

py_test(
    name = "test_virtual_widget",
    srcs = ["//tests/py/vwidgets:test_virtual_widget.py"],
    deps = [
        "//src/api:py_screen_reader",
        requirement("pytest"),
    ],
)



