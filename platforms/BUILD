# Windows platforms
platform(
    name = "windows_x86_64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)
platform(
    name = "windows_aarch64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:aarch64",
    ],
)

# MacOS platforms
platform(
    name = "macos_x86_64",
    constraint_values = [
        "@platforms//os:macos",
        "@platforms//cpu:x86_64",
    ],
)
platform(
    name = "macos_aarch64",
    constraint_values = [
        "@platforms//os:macos",
        "@platforms//cpu:aarch64",
    ],
)

# Linux platforms
platform(
    name = "linux_x86_64",
    constraint_values = [
    "@platforms//os:linux",
        "@platforms//cpu:x86_64"
    ]
)
platform(
    name = "linux_aarch64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:aarch64"
    ]
)

# config_settings and constraint_values definitions
# use them with `select()` to select the correct tag for wheels
config_setting(
    name = "is_windows_x86_64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)

config_setting(
    name = "is_windows_aarch64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:aarch64",
    ],
)

config_setting(
    name = "is_macos_x86_64",
    constraint_values = [
        "@platforms//os:macos",
        "@platforms//cpu:x86_64",
    ],
)

config_setting(
    name = "is_macos_aarch64",
    constraint_values = [
        "@platforms//os:macos",
        "@platforms//cpu:aarch64",
    ],
)

config_setting(
    name = "is_linux_x86_64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
)

config_setting(
    name = "is_linux_aarch64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:aarch64",
    ],
)
