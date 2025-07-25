import pytest
from PyScreenReader.virtual_widgets import VirtualUnknownWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    assert_all_base_functions_exist(VirtualUnknownWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualUnknownWidget, [VirtualWidget])


@pytest.fixture
def widget() -> VirtualUnknownWidget:
    return VirtualUnknownWidget()


def test_widget_name(widget: VirtualUnknownWidget):
    assert widget.get_widget_name() == "VirtualUnknownWidget"
