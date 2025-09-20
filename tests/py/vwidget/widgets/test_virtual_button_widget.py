"""Tests for VirtualButtonWidget class."""

import pytest
from PyScreenReader.virtual_widgets import VirtualButtonWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    """Test that all base methods are implemented."""
    assert_all_base_functions_exist(VirtualButtonWidget)


def test_inheritance():
    """Test that VirtualButtonWidget inherits from the correct classes."""
    assert_correct_inheritance(VirtualButtonWidget, [VirtualWidget])


def test_widget_name(widget: VirtualButtonWidget):
    """Test the widget name is correctly set."""
    assert widget.get_widget_name() == "VirtualButtonWidget"


def test_repr_str(widget: VirtualButtonWidget):
    """Test string representation of the widget."""
    expected_str = (
        "{VirtualButtonWidget, title=, help=, x=0, y=0, width=0, height=0, visible=false}"
    )
    assert str(widget) == expected_str
    assert repr(widget) == expected_str

    widget.set_x(1)
    widget.set_y(2)
    widget.set_width(3)
    widget.set_height(4)
    widget.set_help_text("help")
    widget.set_title_text("title")
    widget.set_visible(True)
    expected_str = (
        "{VirtualButtonWidget, title=title, help=help, x=1, y=2, width=3, height=4, visible=true}"
    )
    assert str(widget) == expected_str
    assert repr(widget) == expected_str


@pytest.fixture
def widget() -> VirtualButtonWidget:
    return VirtualButtonWidget()
