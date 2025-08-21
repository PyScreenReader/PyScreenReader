import pytest
from PyScreenReader.virtual_widgets import VirtualGroupWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    assert_all_base_functions_exist(VirtualGroupWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualGroupWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualGroupWidget:
    return VirtualGroupWidget()


def test_widget_name(widget: VirtualGroupWidget):
    assert widget.get_widget_name() == "VirtualGroupWidget"
