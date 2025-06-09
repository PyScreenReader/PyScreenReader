import pytest
from PyScreenReader import VirtualTextWidget, VirtualWidget

from tests.py.tools.utils import (
    assert_all_base_functions_exist,
    assert_correct_inheritance,
    assert_functions_exist,
)


def test_base_methods():
    assert_all_base_functions_exist(VirtualTextWidget)


def test_additional_methods():
    assert_functions_exist(VirtualTextWidget, ["set_selected_text", "get_selected_text"])


def test_inheritance():
    assert_correct_inheritance(VirtualTextWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualTextWidget:
    return VirtualTextWidget()


def test_selected_text_setter_getter(widget: VirtualTextWidget):
    assert widget.get_selected_text() == "", "selected text should default to empty string"
    widget.set_selected_text("Selected Text")
    assert widget.get_selected_text() == "Selected Text"


def test_widget_name(widget: VirtualTextWidget):
    assert widget.get_widget_name() == "VirtualTextWidget"
