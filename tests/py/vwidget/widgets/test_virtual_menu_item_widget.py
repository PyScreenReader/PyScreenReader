import pytest
from PyScreenReader.virtual_widgets import VirtualMenuItemWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    assert_all_base_functions_exist(VirtualMenuItemWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualMenuItemWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualMenuItemWidget:
    return VirtualMenuItemWidget()


def test_widget_name(widget: VirtualMenuItemWidget):
    assert widget.get_widget_name() == "VirtualMenuItemWidget"
