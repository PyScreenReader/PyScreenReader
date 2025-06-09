import pytest

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance, assert_functions_exist
from PyScreenReader import VirtualWindowWidget, VirtualWidget


def test_base_methods():
    assert_all_base_functions_exist(VirtualWindowWidget)


def test_additional_methods():
    assert_functions_exist(VirtualWindowWidget, ["is_modal", "set_is_modal"])


def test_inheritance():
    assert_correct_inheritance(VirtualWindowWidget, [VirtualWidget])


@pytest.fixture
def widget():
    return VirtualWindowWidget()


def test_is_modal_setter_getter(widget):
    assert widget.is_modal() == False, "is_modal should default to false"
    widget.set_is_modal(True)
    assert widget.is_modal()


def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualWindowWidget"
