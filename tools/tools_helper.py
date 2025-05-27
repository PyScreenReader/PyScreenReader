"""Provides platform-related, bazel sandbox related helper functions."""

import os
import sys
from pathlib import Path

BAZEL_WORKSPACE_ENV_KEY = "BUILD_WORKSPACE_DIRECTORY"

def is_windows() -> bool:
    """Check if the current platform is windows.

    :return: true if the current platform is windows, otherwise false
    """
    return sys.platform == "win32" or sys.platform == "cygwin"

def is_macos() -> bool:
    """Check if the current platform is macOS.

    :return: true if the current platform is macOS, otherwise false
    """
    return sys.platform == "darwin"

def is_linux() -> bool:
    """Check if the current platform is linux.

    :return: true if the current platform is linux, otherwise false
    """
    return sys.platform == "linux"

def get_executable_suffix() -> str:
    """Get the correct suffix for executables on the current platform.

    :return: suffix for executables on current platform
    """
    return ".exe" if is_windows() else ""

def get_source_code_root() -> Path:
    """Retrieve the root of the project source code.

    :return: root directory of the source code
    """
    return Path(os.environ.get(BAZEL_WORKSPACE_ENV_KEY, Path.cwd()))
