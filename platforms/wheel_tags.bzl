"""
Python wheel tag format is {distribution}-{version}(-{build tag})?-{python tag}-{abi tag}-{platform tag}.whl.
In this file, we provide all the necessary information to define a python wheel tags.
https://packaging.python.org/en/latest/specifications/platform-compatibility-tags/
"""

python_version_string = "3.13"
abi_tag = "abi3"
release_version = "0.0.1"

platform_tag = select({
    "//platforms:is_windows_x86_64": "win_amd64",
    "//platforms:is_windows_aarch64": "win_arm64",
    "//platforms:is_macos_x86_64": "macosx_11_0_x86_64",
    "//platforms:is_macos_aarch64": "macosx_11_0_arm64",
    "//platforms:is_linux_x86_64": "manylinux2014_x86_64",
    "//platforms:is_linux_aarch64": "manylinux2014_aarch64",
    "//conditions:default": "unknown_unknown",
})

python_tag = "cp" + python_version_string.replace(".", "")

# Trove Classifiers
# https://pypi.org/classifiers/
trove_classifiers = [
    "Operating System :: Microsoft :: Windows",
    "Operating System :: MacOS",
    "Operating System :: POSIX :: Linux",
    "Topic :: Desktop Environment :: Gnome",
    "Development Status :: 1 - Planning",
    "Programming Language :: C++",
    "Topic :: Software Development :: Libraries :: Application Frameworks",
    "Topic :: Software Development :: Libraries",
    "Typing :: Typed",
    "Topic :: Utilities",
    "License :: OSI Approved :: MIT License"
]

