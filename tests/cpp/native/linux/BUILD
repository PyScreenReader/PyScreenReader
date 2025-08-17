load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

gtest_test(
    name = "test_screen_reader_impl_linux",
    srcs = [":test_screen_reader_impl_linux.cpp"],
    deps = ["//src/native/linux:screen_reader_impl_linux"],
    platform = "linux",
    size = "medium",
    no_ci = True,
)
