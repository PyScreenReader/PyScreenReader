import PyScreenReader as psr

from tests.py.tools.test_utils import assert_method_definitions, assert_getters_setters


def test_functionality():
    assert_getters_setters(psr.VirtualButtonWidget, 'VirtualButtonWidget', True)


def test_method_defs():
    assert_method_definitions(psr.VirtualButtonWidget)
