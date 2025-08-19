load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

gtest_test(
    name = "test_screen_reader_impl_linux",
    size = "medium",
    srcs = [":test_screen_reader_impl_linux.cpp"],
    no_ci = True,
    platform = "linux",
    deps = ["//src/native/linux:screen_reader_impl_linux"],
)
