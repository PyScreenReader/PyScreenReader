load("@pytest_env//:requirements.bzl", "requirement")
load("//tests/py/tools:pytest_defs.bzl", "pytest_suite")

package(default_visibility = ["//visibility:public"])

pytest_suite(
    test_files = glob(["**/test_*.py"]),
    deps = [
        requirement("hypothesis"),
    ],
)
