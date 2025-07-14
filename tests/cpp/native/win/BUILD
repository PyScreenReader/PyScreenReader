load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

package(default_visibility = ["//visibility:public"])

gtest_test(
    name = "test_screen_reader_win_mac",
    size = "medium",
    srcs = [":test_screen_reader_impl_win.cpp"],
    no_ci = True,
    platform = "win",
    deps = ["//src/api:screen_reader"],
)
