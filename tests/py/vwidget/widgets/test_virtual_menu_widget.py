import pytest
from PyScreenReader import VirtualMenuWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    assert_all_base_functions_exist(VirtualMenuWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualMenuWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualMenuWidget:
    return VirtualMenuWidget()


def test_widget_name(widget: VirtualMenuWidget):
    assert widget.get_widget_name() == "VirtualMenuWidget"
