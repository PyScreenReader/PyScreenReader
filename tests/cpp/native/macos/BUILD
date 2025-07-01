load("//tests/cpp/tools:gtest_defs.bzl", "gtest_test")

gtest_test(
    name = "test_cf_utils",
    srcs = [":utils/test_cf_utils.cpp"],
    deps = ["//src/native/macos/utils:cf_utils"],
    platform = "macos",
    linkopts = ["-framework ApplicationServices"],
)

gtest_test(
    name = "test_cf_utils_no_ci",
    srcs = [":utils/test_cf_utils_no_ci.cpp"],
    deps = ["//src/native/macos/utils:cf_utils"],
    platform = "macos",
    size = "medium",
    no_ci = True,
    linkopts = ["-framework ApplicationServices"],
)

gtest_test(
    name = "test_system_utils",
    srcs = [":utils/test_system_utils.cpp"],
    deps = ["//src/native/macos/utils:system_utils"],
    platform = "macos",
    size = "small",
    no_ci = True,
    linkopts = ["-framework ApplicationServices"],
)

gtest_test(
    name = "test_screen_reader_impl_mac",
    srcs = [":test_screen_reader_impl_mac.cpp"],
    deps = ["//src/native/macos:screen_reader_impl_mac"],
    platform = "macos",
    size = "medium",
    no_ci = True,
    linkopts = ["-framework ApplicationServices"],
)
