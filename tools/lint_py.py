import os.path
import subprocess
import sys
from argparse import ArgumentParser


def _run_ruff(fix: bool) -> int:
    project_root = os.path.abspath(os.path.dirname(__file__))

    command = [sys.executable, "-m", "ruff", "check"]

    if fix:
        command.append("--fix")

    res = subprocess.run(
        command,
        stdout=subprocess.PIPE,
        cwd=project_root,
        encoding="utf-8",
    )

    if res.stdout:
        print(res.stdout)

    return res.returncode

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument("-f", "--fix", action="store_true")
    parser.set_defaults(fix=True)
    args = parser.parse_args()

    sys.exit(_run_ruff(fix=args.fix))
