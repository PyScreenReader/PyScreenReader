"""
Python wheel tag format is {distribution}-{version}(-{build tag})?-{python tag}-{abi tag}-{platform tag}.whl.
In this file, we provide all the necessary information to define a python wheel tags.
https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/
"""

abi_tag = "abi3"
python_version_string = "3.11"
release_version = "0.0.1"

os_name = select({
    "@platforms//os:macos": "macosx",
    "@platforms//os:windows": "win",
    # TODO (#10): what is the minimum glibc version on linux?
    # https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/#manylinux
    "@platforms//os:linux": "manylinux2014"
})

os_version = select({
    "@platforms//os:macos": "11_0",
    "@platforms//os:windows": "",
    "@platforms//os:linux": ""
})

arch_name = select({
    "//platforms:is_windows_x86_64": "amd64",
    "//platforms:is_windows_aarch64": "arm64",
    # TODO (#10): should we distinguish arm and amd, or just use `universal2`?
    # https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/#macos
    "//platforms:is_macos_x86_64": "x86_64",
    "//platforms:is_macos_aarch64": "arm64",
    "//platforms:is_linux_x86_64": "x86_64",
    "//platforms:is_linux_aarch64": "aarch64",
    "//conditions:default": "unknown",
})

platform_tag = os_name + "_" + ((os_version + "_") if os_version else "") + arch_name

python_tag = "cp" + python_version_string.replace(".", "")
