package(default_visibility = ["//visibility:public"])
load("@rules_python//python:pip.bzl", "compile_pip_requirements")
load("@dev_tools_env//:requirements.bzl", "requirement")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

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
    deps = [
        requirement("clang-tidy"),
        "@bazel_tools//tools/python/runfiles",
    ],
    data = [
        ":refresh_compile_commands",
    ]
)
