load("@bazel_skylib//rules:copy_file.bzl", "copy_file")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:packaging.bzl", "py_package", "py_wheel", "py_wheel_dist")
load("@rules_python//python:py_library.bzl", "py_library")
load("//platforms:wheel_tags.bzl", "abi_tag", "platform_tag", "python_tag", "release_version", "trove_classifiers")

package(default_visibility = ["//visibility:public"])

project_name = "PyScreenReader"

# Compiles C++ native code to .so/.pyd files
pybind_extension(
    name = project_name,
    srcs = [
        "//src:bindings.cpp",
        "//src/api:screen_reader.cpp",
    ],
    copts = [
        "-DVERSION_INFO=\"{}\"".format(release_version),
    ],
    deps = [
        "//src/api:screen_reader",
        "//src/vwidget:all_virtual_widgets",
    ],
)

# Readme file target
filegroup(
    name = "readme",
    srcs = ["README.md"],
)

# pack the extension to a wheel
# See Platform Compatibility Tags: https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/
# See Package Formats: https://packaging.python.org/en/latest/discussions/package-formats/
# See sysconfig.platform(): https://docs.python.org/3/library/sysconfig.html#sysconfig.get_platform
py_wheel(
    name = "wheel",
    abi = abi_tag,
    author = "The PyScreenReader Team",
    classifiers = trove_classifiers,
    # https://packaging.python.org/en/latest/specifications/core-metadata/#description-content-type
    description_content_type = "text/markdown; charset=UTF-8; variant=GFM",
    description_file = ":readme",
    distribution = project_name,
    homepage = "https://github.com/PyScreenReader/PyScreenReader",
    license = "MIT",
    platform = platform_tag,
    python_tag = python_tag,
    summary = "PyScreenReader is a cross-platform Python library that wraps native accessibility APIs to collect widget tree information on the screen.",
    version = release_version,
    deps = [
        "//src/stubs:py_stubs",
        project_name,
    ],
)

py_wheel_dist(
    name = "dist",
    out = "dist",
    wheel = ":wheel",
)
