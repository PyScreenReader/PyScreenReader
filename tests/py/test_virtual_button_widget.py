import PyScreenReader as psr
from test_utils import assert_getters_setters, assert_method_definitions


def test_functionality():
    assert_getters_setters(psr.VirtualButtonWidget, 'VirtualButtonWidget', True)


def test_method_defs():
    assert_method_definitions(psr.VirtualButtonWidget)
