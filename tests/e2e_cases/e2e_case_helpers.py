import os


def create_done_mark(path: os.PathLike, test_case_name: str) -> None:
    f"""
    Create a {test_case_name}.done file in the given path.
    
    The integration test cases (in tests/e2e_cases) and the test assertion codes (in tests/py/...) are 
    operated as two separate processes, so they don't communicate with each other.
    
    Since the subprocess (test cases) takes time to spin up, right now, we are just blindly waiting for
    a fix timeout and pray the test cases will spin up in time, which is not ideal.
    
    This function creates a file at the given path. The presence of the file is a signal for the test
    target is ready, then the test runner will proceed with assertions.
    
    :param path: path to create the file in
    :param test_case_name: name of the test case
    """
    with open(f"{path}/{test_case_name}.done", "w") as f:
        f.write("")

