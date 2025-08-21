from PyScreenReader.virtual_widgets import NumericValueWidget, VirtualWidget

from tests.py.tools.utils import (
    assert_abstract_class,
    assert_all_base_functions_exist,
    assert_correct_inheritance,
)


def test_abstract_class():
    assert_abstract_class(NumericValueWidget)


def test_base_methods():
    assert_all_base_functions_exist(NumericValueWidget)


def test_inheritance():
    assert_correct_inheritance(NumericValueWidget, [VirtualWidget])
