import pytest
from PyScreenReader.virtual_widgets import NumericValueWidget, VirtualSpinnerWidget, VirtualWidget

from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance


def test_base_methods():
    assert_all_base_functions_exist(VirtualSpinnerWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualSpinnerWidget, [NumericValueWidget, VirtualWidget])


@pytest.fixture
def widget() -> VirtualSpinnerWidget:
    return VirtualSpinnerWidget()


def test_widget_name(widget: VirtualSpinnerWidget):
    assert widget.get_widget_name() == "VirtualSpinnerWidget"
