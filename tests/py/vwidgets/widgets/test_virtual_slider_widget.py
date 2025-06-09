from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance, assert_functions_exist
from PyScreenReader import VirtualSliderWidget, NumericValueWidget, VirtualWidget, Orientation
import pytest


def test_base_methods():
    assert_all_base_functions_exist(VirtualSliderWidget)


def test_additional_methods():
    assert_functions_exist(VirtualSliderWidget, ["set_orientation", "get_orientation"])


def test_inheritance():
    assert_correct_inheritance(VirtualSliderWidget, [NumericValueWidget, VirtualWidget])


@pytest.fixture
def widget():
    return VirtualSliderWidget()


def test_orientation_setter_getter(widget):
    # Default value is Orientation.VERTICAL
    assert widget.get_orientation() == Orientation.VERTICAL, "default orientation should be vertical"

    widget.set_orientation(Orientation.HORIZONTAL)
    assert widget.get_orientation() == Orientation.HORIZONTAL


def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualSliderWidget"
