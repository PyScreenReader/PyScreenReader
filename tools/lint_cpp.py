import logging
import os
import subprocess
import sys
from pathlib import Path

from bazel_tools.tools.python.runfiles import runfiles

# We have to do import _run to get this work, although it is a member func
from clang_tidy import _run
from tools_helper import (
    get_executable_suffix,
    get_source_code_root,
    is_macos,
    is_windows,
)

CPP_EXTENSIONS = frozenset((".h", ".hpp", ".c", ".cpp", ".cc"))
CLANG_TIDY_NAME = "clang-tidy"

COMMON_SOURCE_FILE_DIRS = frozenset(("tests", "include", "tools"))
MACOS_SPECIFIC_SOURCE_FILE_DIRS = frozenset(("src/native/macos",))
WIN_SPECIFIC_SOURCE_FILE_DIRS = frozenset(("src/native/win",))

logger = logging.getLogger(__name__)
logging.basicConfig(level=logging.INFO)


def _find_macos_sdk_path() -> str | None:
    """Find macOS sdk path.

    If any errors occurred, a fallback of "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
    will be returned

    :return: macOS sdk search path
    """
    fallback_path = "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
    try:
        cmd_output = subprocess.run(
            ["xcrun", "--show-sdk-path"],
            stdout=subprocess.PIPE,
            text=True,
            check=True,
        )
    except subprocess.CalledProcessError as e:
        logger.warning(f"macOS SDK default fallback path is provided, due to {e.stdout}")
        return fallback_path

    if not cmd_output.stdout or not cmd_output.stdout.strip():
        logger.warning("macOS SDK default fallback path is provided")
        return fallback_path
    sdk_path = cmd_output.stdout.strip()

    return f"{sdk_path}/System/Library/Frameworks"


def _find_macos_cpp_libs() -> list[str]:
    """Locate all local macOS cpp libs

    :return: paths to local macOS cpp libs
    """
    try:
        result = subprocess.run(
            ["clang++", "-E", "-x", "c++", "-", "-v"],
            stdin=subprocess.DEVNULL,
            stderr=subprocess.PIPE,
            text=True,
            check=True,
        )
    except subprocess.CalledProcessError:
        logger.warning("Unable to locate macOS native libs automatically")
        return []

    lib_paths = []
    in_include = False
    for line in result.stderr.splitlines():
        if "#include <...> search starts here" in line:
            in_include = True
            continue
        if "End of search list" in line:
            in_include = False
            continue
        if in_include:
            path = line.strip()
            if Path(path).exists():
                lib_paths.append(path)
    return lib_paths



def _find_platform_dependent_args() -> list[str]:
    """Find platform dependent args when running clang-tidy.

    For example, on macOS, the compile database does not collect system libs properly,
    We have to patch with the following py script to correctly locate and link those libs

    :return: a list of platform dependent args to append when running clang-tidy
    """
    if is_macos():
        # We only run the following patch on macOS
        include_args = [f"--extra-arg=-isystem{lib_path}" for lib_path in _find_macos_cpp_libs()]
        include_args.append(f"--extra-arg=-F{_find_macos_sdk_path()}")

        # Clang-tidy throws a lot of no-elaborated-enum-base in macOS sdk, disabling it here
        include_args.append("--extra-arg=-Wno-elaborated-enum-base")
        return include_args
    # If in the future, patches are needed for other platforms, please add them here.

    return []


def _generate_compile_commands(project_root: Path) -> os.PathLike:
    """Generate compile database and return the path to it.

    :param project_root: project root path
    :return: compile database path
    """
    r = runfiles.Create()
    binary_path = r.Rlocation(f"_main/tools/refresh_compile_commands{get_executable_suffix()}")
    if not os.path.exists(binary_path):
        raise FileNotFoundError("refresh_compile_commands binary is not found, thus cannot generate compile database")
    result = subprocess.run(binary_path, stdin=subprocess.DEVNULL,
                   stderr=subprocess.PIPE,
                   text=True,
                   check=True)
    logger.info("Compile command output: %s", result.stderr)
    return project_root / "compile_commands.json"


def _collect_source_files(project_root: Path) -> list[os.PathLike]:
    """Collect source files selectively.
    We only want to collect the source files corresponding to the current platform for linting
    Otherwise, clang-tidy will complain because clang-tidy cannot link to libs from other platform.

    :param project_root: project root path
    :return: a list of source files to lint
    """
    source_files = []
    source_file_dirs = COMMON_SOURCE_FILE_DIRS
    if is_macos():
        source_file_dirs = source_file_dirs.union(MACOS_SPECIFIC_SOURCE_FILE_DIRS)
    elif is_windows():
        source_file_dirs = source_file_dirs.union(WIN_SPECIFIC_SOURCE_FILE_DIRS)

    for src_dir in source_file_dirs:
        for root, _, files in os.walk(project_root / src_dir):
            for file in files:
                if Path(file).suffix in CPP_EXTENSIONS:
                    source_files.append(Path(root) / file)
    return source_files


def _run_clang_tidy(compile_commands_path: os.PathLike, files: list[os.PathLike]) -> int:
    """Run clang-tidy.

    :param compile_commands_path: path to compile database
    :param files: C++ source files
    :return: return code
            0 if no error occurred and linter passed
            1 if error occurred or linter did not pass
    """
    cmd = [f"-p={compile_commands_path}", "--quiet"]
    cmd.extend(_find_platform_dependent_args())
    logger.info("Args given to clang-tidy: %s", cmd)
    cmd.extend(files)
    return _run(CLANG_TIDY_NAME, *cmd)


def main() -> int:
    """Entry point of this script.

    :return: system return code
        - 0 if no error and linter passed
        - 1 if errors occurs or linter rejected
    """
    project_root = get_source_code_root()

    # Step 1: Build compile_commands.json
    compile_commands = _generate_compile_commands(project_root)

    # Step 2: Collect all C++ source files
    source_files = _collect_source_files(project_root)
    if not source_files:
        logger.warning("No C++ source files found.")
        return 0

    # Step 3: Run clang-tidy
    return _run_clang_tidy(compile_commands, source_files)


if __name__ == "__main__":
    sys.exit(main())
