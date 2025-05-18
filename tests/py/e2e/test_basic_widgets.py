from tests.py.tools.e2e_test_case_process import E2ETestCaseProcess
import PyScreenReader as psr


def test_basic_widgets():
    with E2ETestCaseProcess("basic_widgets_case") as pid:
        screen_reader = psr.ScreenReader()
        root = screen_reader.getVirtualWidgetTreeByPID(pid)
        print(">>>>>>>>", pid)
        print(root)
        assert False
