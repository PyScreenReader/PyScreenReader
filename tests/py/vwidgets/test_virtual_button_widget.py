import PyScreenReader as psr

from tests.py.tools.test_utils import (
    assert_getters_setters,
    assert_method_definitions,
)


def test_functionality():
    assert_getters_setters(psr.VirtualButtonWidget, "VirtualButtonWidget", true_is_clickable=True)


def test_method_defs():
    assert_method_definitions(psr.VirtualButtonWidget)
