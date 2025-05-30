"""Runs Ruff linter and formatter on source code.

Usage: bazel run //tools:lint_py -- [-f|--fix] [--no-format]

Options:
  -f, --fix     Automatically fix lint issues
                (By default this is disabled).
  --no-format   Disable formatter (By default formatter is enabled)

Make sure `ruff` is installed: https://docs.astral.sh/ruff/installation/

Note:
    COM812 warns about missing trailing commas, which is fixed by ruff format.
    We intentionally keep this enabled for linting consistency:

    warning: The following rule may cause conflicts when used with the formatter:
    `COM812`. To avoid unexpected behavior, we recommend disabling this rule, either by removing it
    from the `lint.select` or `lint.extend-select` configuration, or adding it to the `lint.ignore`
    configuration.

"""

import subprocess
import sys
from argparse import ArgumentParser

from tools.tools_helper import get_source_code_root

project_root = get_source_code_root()


def _run_command(command: list[str]) -> int:
    try:
        res = subprocess.run(
            command,
            capture_output=True,
            cwd=project_root,
            encoding="utf-8",
            check=False,
        )
        if res.stdout:
            print(res.stdout)
        if res.stderr:
            print(res.stderr)
    except FileNotFoundError as error:
        print("Oops, it seems `ruff` was not found anywhere. Please try to install it:")
        print("https://docs.astral.sh/ruff/installation/")
        print(error)
        return 1
    else:
        return res.returncode


def _run_ruff_format(no_format: bool) -> int:
    print("Running `ruff format`...")
    command = ["ruff", "format", "."]
    if no_format:
        command.append("--diff")
    return _run_command(command)


def _run_ruff_check(fix: bool) -> int:
    print("Running `ruff check`...")
    command = ["ruff", "check", "."]
    if fix:
        command.append("--fix")
    return _run_command(command)


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("-f", "--fix", action="store_true", help="Fix lint issues")
    parser.add_argument(
        "--no-format",
        dest="no_format",
        action="store_true",
        help="Disable ruff formatter",
    )
    args = parser.parse_args()

    format_code = _run_ruff_format(args.no_format)
    sys.exit(_run_ruff_check(fix=args.fix))
