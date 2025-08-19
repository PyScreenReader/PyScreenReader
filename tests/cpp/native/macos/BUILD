load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

gtest_test(
    name = "test_cf_utils",
    srcs = [":utils/test_cf_utils.cpp"],
    linkopts = ["-framework ApplicationServices"],
    platform = "macos",
    deps = ["//src/native/macos/utils:cf_utils"],
)

gtest_test(
    name = "test_cf_utils_no_ci",
    size = "medium",
    srcs = [":utils/test_cf_utils_no_ci.cpp"],
    linkopts = ["-framework ApplicationServices"],
    no_ci = True,
    platform = "macos",
    deps = ["//src/native/macos/utils:cf_utils"],
)

gtest_test(
    name = "test_system_utils",
    size = "small",
    srcs = [":utils/test_system_utils.cpp"],
    linkopts = ["-framework ApplicationServices"],
    no_ci = True,
    platform = "macos",
    deps = ["//src/native/macos/utils:system_utils"],
)

gtest_test(
    name = "test_screen_reader_impl_mac",
    size = "medium",
    srcs = [":test_screen_reader_impl_mac.cpp"],
    linkopts = ["-framework ApplicationServices"],
    no_ci = True,
    platform = "macos",
    deps = ["//src/native/macos:screen_reader_impl_mac"],
)
