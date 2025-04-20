import sys
import pytest

PY_TEST_DEFAULT_ARGS = ['-vv']

if __name__ == "__main__":
    sys.exit(pytest.main(sys.argv[1:] + PY_TEST_DEFAULT_ARGS))