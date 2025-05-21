import os.path
from signal import SIGTERM
import subprocess
import time
from subprocess import Popen

from tools.tools_helper import get_executable_suffix

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
    POLLING_THROTTLE_S = 1     # 1 second
    POLLING_TIMEOUT_S = 20     # 20 seconds
    BAZEL_RUNTIME_PREFIX = "_main/tests/e2e_cases/"

    def __init__(self, case_name: str):
        """
        Initialize the test process

        :param case_name: name of the E2E test case (No need for any prefix or suffix)
            For example, "basic_widgets_case" is a valid case name
        """
        self.case_name = case_name
        self.popen_process: Popen | None = None

        # Figure out the path of the binary target inside bazel sandbox
        r = runfiles.Create()
        self.binary_path = r.Rlocation(f"{self.BAZEL_RUNTIME_PREFIX}{self.case_name}{get_executable_suffix()}")

        # Since we don't want to blindly wait for the target test case to spin up, we implement
        #  the logic in the test cases to produce a [case_name].done file as a signal for the test case is ready
        self.marker_path = r.Rlocation(f"{self.BAZEL_RUNTIME_PREFIX}{self.case_name}.done")

    def __enter__(self) -> str:
        if not os.path.exists(self.binary_path):
            # If this is raised, please check if in your pytest BUILD file, do you have the e2e target in `data`
            raise FileNotFoundError("E2E test target not found, did you forget to add it to the data field " +
                                    "of your test case in the corresponding BUILD file?")

        # Start the subprocess running the target script
        self.popen_process = subprocess.Popen([self.binary_path])

        start_time = time.time()
        while not os.path.exists(self.marker_path):
            if time.time() - start_time > E2ETestCaseProcess.POLLING_TIMEOUT_S:
                raise TimeoutError(f'The target E2E test case "{self.case_name}" failed '
                                   f'to spin up in timeout of {E2ETestCaseProcess.POLLING_TIMEOUT_S} seconds')
            # os.path.exists is relatively slow and resource-consuming, so we add throttle
            # Therefore, this loop will run at most POLLING_TIMEOUT_S // POLLING_THROTTLE_S times
            time.sleep(E2ETestCaseProcess.POLLING_THROTTLE_S)
        return str(self.popen_process.pid)

    def __exit__(self, _exc_type, _exc_val, _exc_tb):
        if os.path.exists(self.marker_path):
            os.remove(self.marker_path)

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
