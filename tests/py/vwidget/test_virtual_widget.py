from PyScreenReader.virtual_widgets import VirtualWidget

from tests.py.tools.utils import assert_abstract_class, assert_all_base_functions_exist


def test_abstract_class():
    assert_abstract_class(VirtualWidget)


def test_base_methods():
    assert_all_base_functions_exist(VirtualWidget)
