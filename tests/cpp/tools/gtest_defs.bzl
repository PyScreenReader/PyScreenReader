load("@pybind11_bazel//:build_defs.bzl", "pybind_library_test")

def gtest_test(name, srcs, deps, platform, size="small", **kwargs):
    """
    Build a PyScreenReader gtest target
    This function wraps the pybind_library_test

    :param name: test target name
    :param srcs: source files of the test
    :param deps: dependency of the test case (gtest is implicitly injected)
    :param platform: env this test can be built for - either "macos", "win" or "linux".
    :param size: heaviness of the test (unit test = small, integration = medium, e2e = large)
                 This size will be used to determine the timeout.
    :param **kwargs: additional args to pass to original pybind_library_test target
    """

    if platform == "win":
        compatible_platform = ["@platforms//os:windows"]
    elif platform == "macos":
        compatible_platform = ["@platforms//os:macos"]
    elif platform == "linux":
        compatible_platform = ["@platforms//os:linux"]
    else:
        compatible_platform = [
            "@platforms//os:windows",
            "@platforms//os:macos",
            "@platforms//os:linux",
        ]

    pybind_library_test(
        name = name,
        srcs = srcs,
        size = size,
        target_compatible_with = compatible_platform,
        deps = deps + ["@googletest//:gtest", "@googletest//:gtest_main"]
    )
