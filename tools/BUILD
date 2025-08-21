load("@buildifier_prebuilt//:rules.bzl", "buildifier")
load("@dev_tools_env//:requirements.bzl", "requirement")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")

package(default_visibility = ["//visibility:public"])

compile_pip_requirements(
    name = "requirements",
    src = "//tools:requirements.in",
    requirements_txt = "//tools:requirements_lock.txt",
)

py_binary(
    name = "download_wheels",
    srcs = ["download_wheels.py"],
    deps = [
        requirement("beautifulsoup4"),
        requirement("urllib3"),
    ],
)

# Debug Tools Config
cc_binary(
    name = "cpp_inspect",
    srcs = ["cpp_inspect.cpp"],
    deps = [
        "//src/api:screen_reader",
        "@cxxopts",
    ],
)

py_binary(
    name = "py_inspect",
    srcs = ["py_inspect.py"],
    deps = [
        "//:PyScreenReader",
    ],
)

py_binary(
    name = "generate_doc",
    srcs = ["generate_doc.py"],
    deps = [
        requirement("pybind11-stubgen"),
    ],
)

# Buildifier Config
buildifier(
    name = "buildifier.fix",
    exclude_patterns = [
        "./.git/*",
    ],
    mode = "fix",
)
