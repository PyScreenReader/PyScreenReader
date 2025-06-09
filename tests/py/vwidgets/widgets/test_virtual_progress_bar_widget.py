from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance, assert_functions_exist
from PyScreenReader import VirtualProgressBarWidget, NumericValueWidget, VirtualWidget, Orientation
import pytest


def test_base_methods():
    assert_all_base_functions_exist(VirtualProgressBarWidget)


def test_additional_methods():
    assert_functions_exist(VirtualProgressBarWidget, ["set_orientation", "get_orientation"])


def test_inheritance():
    assert_correct_inheritance(VirtualProgressBarWidget, [NumericValueWidget, VirtualWidget])


@pytest.fixture
def widget():
    return VirtualProgressBarWidget()


def test_orientation_setter_getter(widget):
    # Default value is Orientation.VERTICAL
    assert widget.get_orientation() == Orientation.VERTICAL, "default orientation should be vertical"

    widget.set_orientation(Orientation.HORIZONTAL)
    assert widget.get_orientation() == Orientation.HORIZONTAL

def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualProgressBarWidget"
