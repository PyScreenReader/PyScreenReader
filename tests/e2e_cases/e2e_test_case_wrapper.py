import os
import datetime
from pathlib import Path
import logging

from PySide6.QtWidgets import QWidget
from PySide6.QtCore import QTimer

class E2ETestCaseWrapper(QWidget):

    def __init__(self, test_case_name: str) -> None:
        """
        Initialize E2ETestCaseWrapper

        :param test_case_name: current
        """
        super().__init__()

        logging.basicConfig(level=logging.DEBUG)
        self.test_case_name = test_case_name

    def _create_done_file(self) -> None:
        """
        Create a [test_case_name].done file in "tests/e2e_cases" dir of the runtime sandbox.

        The integration test cases (in tests/e2e_cases) and the test assertion codes (test runners in tests/py/...) are
        operated as two separate processes, so they don't communicate with each other.

        Since the subprocess (test cases) takes time to spin up, right now, we are just blindly waiting for
        a fix timeout and pray the test cases will spin up in time, which is not ideal. Therefore, we have this python code.
        This function creates a file in the runtime sandbox. The presence of the file is a signal for the test
        target is ready, then the test runner will proceed with assertions.
        """
        path = Path("./tests/e2e_cases")
        abs_path = os.path.abspath(f"{path}/{self.test_case_name}.done")
        logging.info("Creating 'done' file at %s", abs_path)

        with open(abs_path, "w") as f:
            f.write(datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S.%f"))

        assert os.path.exists(abs_path)

    def signal_completion(self) -> None:
        """
        Signal the test runner that the current test case is up.
        """
        # QTimer.singleShot(0, func) ensures the function runs after the layout has been initialized
        QTimer.singleShot(0, self._create_done_file)
