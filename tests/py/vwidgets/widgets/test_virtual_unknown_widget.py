import pytest

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance
from PyScreenReader import VirtualUnknownWidget, VirtualWidget


def test_base_methods():
    assert_all_base_functions_exist(VirtualUnknownWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualUnknownWidget, [VirtualWidget])


@pytest.fixture
def widget():
    return VirtualUnknownWidget()


def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualUnknownWidget"
