import os
import sys
import subprocess
from pathlib import Path
from typing import List

from bazel_tools.tools.python.runfiles import runfiles

# We have to do import _run to get this work, although it is a member func
from clang_tidy import _run

CPP_EXTENSIONS = frozenset((".h", ".hpp", ".c", ".cpp", ".cc"))
BAZEL_WORKSPACE_ENV_KEY = "BUILD_WORKSPACE_DIRECTORY"
CLANG_TIDY_NAME = "clang-tidy"
SOURCE_FILE_DIRS = frozenset(("src", "include", "tests"))


def _find_platform_dependent_args() -> List[str]:
    """
    Find platform dependent args when running clang-tidy.

    For example, on macOS, the compile data does not collect system libs properly,
    We have to use the following py script to correctly locate and link those libs

    :return: a list of platform dependent args to append when running clang-tidy
    """
    if sys.platform == 'darwin':
        # If the platform is macOS
        # NOTE: on ios sys.platform could also be "darwin", but no one is using or should use iphone to develop this project
        result = subprocess.run(
            ["clang++", "-E", "-x", "c++", "-", "-v"],
            stdin=subprocess.DEVNULL,
            stderr=subprocess.PIPE,
            text=True,
            check=True,
        )
        includes_args = []
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
                    includes_args.append(f"--extra-arg=-I{path}")
        return includes_args
    # If in the future, patches are needed for other platforms, please add them here.
    return []


def _generate_compile_commands(project_root: Path) -> os.PathLike:
    """
    Generate compile database and return the path

    :param project_root: project root path
    :return: compile database path
    """
    r = runfiles.Create()
    binary_path = r.Rlocation("_main/tools/refresh_compile_commands")
    if not os.path.exists(binary_path):
        raise FileNotFoundError("refresh_compile_commands binary is not found, thus cannot generate compile database")
    result = subprocess.run(binary_path, stdin=subprocess.DEVNULL,
                   stderr=subprocess.PIPE,
                   text=True,
                   check=True)
    print(result.stderr)
    return project_root / "compile_commands.json"


def _collect_source_files(project_root: Path) -> List[os.PathLike]:
    """
    Collect all source files

    :param project_root: project root path
    :return: a list of source files to lint
    """
    source_files = []
    for src_dir in SOURCE_FILE_DIRS:
        for root, _, files in os.walk(project_root / src_dir):
            for file in files:
                if Path(file).suffix in CPP_EXTENSIONS:
                    source_files.append(Path(root) / file)
    return source_files


def _run_clang_tidy(compile_commands_path: os.PathLike, files: List[os.PathLike]) -> int:
    """
    Locate clang-tidy executable and run clang-tidy

    :param compile_commands_path: path to compile database
    :param files: C++ source files
    :return: return code
            0 if no error occurred and linter passed
            1 if error occurred or linter did not pass
    """
    cmd = [f"-p={compile_commands_path}", "--quiet", "-header-filter=.*"]
    cmd.extend(_find_platform_dependent_args())
    cmd.extend(files)
    return _run(CLANG_TIDY_NAME, *cmd)


def main() -> int:
    """
    Entry point

    :return: system return code
        - 0 if no error and linter passed
        - 1 if errors occurs or linter rejected
    """
    project_root = Path(os.environ.get(BAZEL_WORKSPACE_ENV_KEY, os.getcwd()))

    # Step 1: Build compile_commands.json
    compile_commands = _generate_compile_commands(project_root)

    # Step 2: Collect all C++ source files
    source_files = _collect_source_files(project_root)
    if not source_files:
        print("No C++ source files found.")
        return 0

    # Step 3: Run clang-tidy
    return _run_clang_tidy(compile_commands, source_files)


if __name__ == "__main__":
    exit(main())
