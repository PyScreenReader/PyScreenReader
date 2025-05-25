load("@dev_tools_env//:requirements.bzl", "requirement")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@rules_python//python:py_library.bzl", "py_library")

package(default_visibility = ["//visibility:public"])

compile_pip_requirements(
    name = "requirements",
    src = "//tools:requirements.in",
    requirements_txt = "//tools:requirements_lock.txt",
)

refresh_compile_commands(
    name = "refresh_compile_commands",
    targets = {
        #       For simplicity purpose, we only build compile database on our main target for now.
        #       This means we are only linting the source files on tree of the main target.
        #       This is fine for now, because it should cover all source files.
        #       For future C++ gtest suites, we need to them here to lint them as well.
        "//:PyScreenReader": "",
    },
)

py_binary(
    name = "lint_cpp",
    srcs = ["lint_cpp.py"],
    data = [
        ":refresh_compile_commands",
    ],
    imports = ["."],
    deps = [
        requirement("clang-tidy"),
        "tools_helper",
        "@bazel_tools//tools/python/runfiles",
    ],
)

py_binary(
    name = "lint_py",
    srcs = ["lint_py.py"],
    deps = [
        requirement("ruff"),
        "tools_helper"
    ]
)

py_library(
    name = "tools_helper",
    srcs = ["tools_helper.py"],
)
