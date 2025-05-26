load("@pybind11_bazel//:build_defs.bzl", "pybind_library_test")

package(default_visibility = ["//visibility:public"])

pybind_library_test(
    name = "test_screen_reader",
    size = "small",
    srcs = ["//src/native/win/gtest:test_screen_reader.cpp"],
    deps = [
        "//src/api:screen_reader",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
