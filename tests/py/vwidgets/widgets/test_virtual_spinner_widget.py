from tests.py.tools.utils import assert_all_base_functions_exist, assert_correct_inheritance
from PyScreenReader import VirtualSpinnerWidget, NumericValueWidget, VirtualWidget

import pytest


def test_base_methods():
    assert_all_base_functions_exist(VirtualSpinnerWidget)


def test_inheritance():
    assert_correct_inheritance(VirtualSpinnerWidget, [NumericValueWidget, VirtualWidget])


@pytest.fixture
def widget():
    return VirtualSpinnerWidget()


def test_widget_name(widget):
    assert widget.get_widget_name() == "VirtualSpinnerWidget"
