import os
import subprocess
import sys
from argparse import ArgumentParser
from pathlib import Path


BAZEL_WORKSPACE_ENV_KEY = "BUILD_WORKSPACE_DIRECTORY"

def _run_ruff(fix: bool) -> int:
    project_root = Path(os.environ.get(BAZEL_WORKSPACE_ENV_KEY, os.getcwd()))

    command = ["ruff", "check"]

    if fix:
        command.append("--fix")

    try:
        res = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            cwd=project_root,
            encoding="utf-8",
        )
        if res.stdout:
            print(res.stdout)
        if res.stderr:
            print(res.stderr)
        return_code = res.returncode

    except FileNotFoundError as error:
        print("Oops, it seems `ruff` was not found anywhere. Please try to install ruff following")
        print("https://docs.astral.sh/ruff/installation/#installing-ruff")
        print(error)

        return_code = 1

    return return_code

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument("-f", "--fix", action="store_true")
    parser.set_defaults(fix=True)
    args = parser.parse_args()

    sys.exit(_run_ruff(fix=args.fix))
