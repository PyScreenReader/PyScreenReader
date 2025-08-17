import pytest
from PyScreenReader import VirtualTextInputWidget, VirtualWidget

from tests.py.tools.utils import (
    assert_all_base_functions_exist,
    assert_correct_inheritance,
    assert_functions_exist,
)


def test_base_methods():
    assert_all_base_functions_exist(VirtualTextInputWidget)


def test_additional_methods():
    assert_functions_exist(
        VirtualTextInputWidget,
        [
            "set_selected_text",
            "get_selected_text",
            "set_insertion_point",
            "get_insertion_point",
            "set_is_text_area",
            "is_text_area",
        ],
    )


def test_inheritance():
    assert_correct_inheritance(VirtualTextInputWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualTextInputWidget:
    return VirtualTextInputWidget()


def test_selected_text_setter_getter(widget: VirtualTextInputWidget):
    assert widget.get_selected_text() == "", "selected text should default to empty string"
    widget.set_selected_text("Selected Text")
    assert widget.get_selected_text() == "Selected Text"


def test_insertion_point_setter_getter(widget: VirtualTextInputWidget):
    assert widget.get_insertion_point() == -1, "insertion_point should default to -1"
    widget.set_insertion_point(10)
    assert widget.get_insertion_point() == 10


def test_text_area_setter_getter(widget: VirtualTextInputWidget):
    assert not widget.is_text_area(), "is_text_area should default to False"
    widget.set_is_text_area(True)
    assert widget.is_text_area()


def test_widget_name(widget: VirtualTextInputWidget):
    assert widget.get_widget_name() == "VirtualTextInputWidget"
