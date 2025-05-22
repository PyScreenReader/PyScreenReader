package(default_visibility = ["//visibility:public"])
load("@pytest_env//:requirements.bzl", "requirement")

py_binary(
    name = "basic_widgets_case",
    srcs = ["basic_widgets_case.py"],
    deps = [
        requirement("pyside6"),
        "e2e_test_case_wrapper"
    ],
)

py_library(
    name = "e2e_test_case_wrapper",
    srcs = [
        requirement("pyside6"),
        "e2e_test_case_wrapper.py"
    ],
)
