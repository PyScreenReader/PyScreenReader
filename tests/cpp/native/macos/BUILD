load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

gtest_test(
    name = "test_cf_utils",
    srcs = [":utils/test_cf_utils.cpp"],
    deps = ["//src/native/macos/utils:cf_utils"],
    platform = "macos"
)