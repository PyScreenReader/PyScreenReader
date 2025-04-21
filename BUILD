load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:py_library.bzl", "py_library")
load("@rules_python//python:packaging.bzl", "py_wheel", "py_package", "py_wheel_dist")
package(default_visibility = ["//visibility:public"])

# Compiles C++ native code to .so/.pyd files
pybind_extension(
    name = "PyScreenReader",
    srcs = [
        "//src:bindings.cpp",
        "//src/api:screen_reader.cpp",
    ],
    deps = [
        "//src/api:screen_reader",
        "//src/vwidget:all_virtual_widgets",
    ],
)

# pack the extension to a wheel
# See Platform Compatibility Tags: https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/
# See Package Formats: https://packaging.python.org/en/latest/discussions/package-formats/
# See sysconfig.platform(): https://docs.python.org/3/library/sysconfig.html#sysconfig.get_platform
py_wheel(
    name = "wheel",
    abi = "abi3",
    author = "The PyScreenReader Team",
    license = "MIT",

    distribution = "PyScreenReader",
# TODO: revisit platform constraints
    platform = select({
        "@platforms//os:macos": "macosx_11_0_universal2",
        "@platforms//os:windows": "win-amd64",
    }),
    python_tag = "cp313",
    version = "0.0.1",
    deps = [":PyScreenReader"],
)

py_wheel_dist(
    name = "dist",
    out = "dist",
    wheel = ":wheel"
)

