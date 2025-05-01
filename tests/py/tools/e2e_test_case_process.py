import os.path
import sys
from signal import SIGTERM
import subprocess
import time
from subprocess import Popen

from bazel_tools.tools.python.runfiles import runfiles

class E2ETestCaseProcess:
    """
    A context manager that runs an end-to-end (E2E) test target as a subprocess,
    waits briefly for it to initialize, and ensures graceful termination upon exit.

    Example:
        In your E2E test file:

        ```python
        with E2ETestCaseProcess("basic_widgets_case") as pid:
            # Perform interactions or assertions while the process is running
        ```
    """

    TERMINATION_TIMEOUT_S = 5  # 5 seconds
    BOOTSTRAP_DELAY_S = 20      # 3 seconds

    def __init__(self, case_name: str):
        """
        Initialize the test process

        :param case_name: name of the E2E test case (No need for any prefix or suffix)
            For example, "basic_widgets_case" is a valid case name
        """
        self.case_name = case_name
        self.popen_process: Popen | None = None

    def __enter__(self) -> str:
        # Figure out the path of the binary target inside bazel sandbox
        r = runfiles.Create()
        binary_path = r.Rlocation(f"_main/tests/e2e_cases/{self.case_name}")
        if not os.path.exists(binary_path):
            # If this is raised, please check if in your pytest BUILD file, do you have the e2e target in `data`
            raise FileNotFoundError("E2E test target not found, did you forget to add it to your test BUILD target?")

        # Start the subprocess running the target script
        self.popen_process = subprocess.Popen([binary_path])
        # Wait briefly to allow the process to initialize (e.g., spin up GUI)
        time.sleep(E2ETestCaseProcess.BOOTSTRAP_DELAY_S)
        return str(self.popen_process.pid)

    def __exit__(self, _exc_type, _exc_val, _exc_tb):
        if not self.popen_process:
            raise OSError("Attempted to terminate a non-existent process.")

        # Gracefully request the process to terminate
        self.popen_process.terminate()

        try:
            # Wait for the process to exit cleanly
            return_code = self.popen_process.wait(E2ETestCaseProcess.TERMINATION_TIMEOUT_S)
        except subprocess.TimeoutExpired:
            # If the process doesn't terminate in time, forcefully kill it
            # We tolerate this to avoid flakiness from OS-level delays
            self.popen_process.kill()
            return

        # Raise an error if the process exited with an unexpected error code
        if return_code not in (0, -SIGTERM):
            raise OSError(f"Process exited with unexpected code: {return_code}.")
