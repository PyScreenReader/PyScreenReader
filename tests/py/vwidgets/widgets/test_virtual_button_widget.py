import pytest

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance
from PyScreenReader import VirtualButtonWidget, VirtualWidget

def test_base_methods():
    assert_all_base_functions_exist(VirtualButtonWidget)

def test_inheritance():
    assert_correct_inheritance(VirtualButtonWidget, [VirtualWidget])


@pytest.fixture
def widget():
    return VirtualButtonWidget()


def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualButtonWidget"
