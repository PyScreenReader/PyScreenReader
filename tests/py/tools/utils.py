import inspect
from typing import List, Iterable

import pytest
from PyScreenReader import VirtualWidget

"""
All the base methods that the children of VirtualWidget should have.
"""
BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET = frozenset([
    "get_title_text",
    "set_title_text",
    "get_help_text",
    "set_help_text",
    "get_native_name",
    "set_native_name",
    "get_x",
    "set_x",
    "get_y",
    "set_y",
    "get_width",
    "set_width",
    "get_height",
    "set_height",
    "is_visible",
    "set_visible",
    "is_focused",
    "set_focused",
    "get_parent",
    "set_parent",
    "get_child",
    "add_child",
    "get_widget_name",
])


def assert_all_base_functions_exist(cls: type[VirtualWidget]) -> None:
    """
    Check if all subclasses (including VirtualWidget) are inheriting the correct methods from VirtualWidget.

    :param cls: class to test
    """
    assert_functions_exist(cls, BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET)


def assert_functions_exist(cls: type[VirtualWidget], method_names: Iterable[str]) -> None:
    """
    Check if all methods in the given list are present in the given class.

    :param cls: class to test
    :param method_names: list of method names
    """
    for method in method_names:
        assert hasattr(cls, method), f"{method} should exist in {cls.__name__}."


def assert_correct_inheritance(cls: type[VirtualWidget], chain: List[type[VirtualWidget]]) -> None:
    """
    Check if current class has the given inheritance chain.

    :param cls: current class
    :param chain: list of super-classes in the chain, starting with the direct parent.
    """
    for idx, parent_class in enumerate(chain, start=1):
        assert inspect.getmro(cls)[idx] == parent_class, \
            (f"Class '{cls}' has the wrong class in the inheritance chain at index {idx}. "
             f"Actual : {inspect.getmro(cls)[idx]} "
             f"Expecting : {parent_class}")


def assert_abstract_class(cls: type[VirtualWidget]) -> None:
    """
    Assert the given class is an abstract class

    :param cls: class
    """
    with pytest.raises(TypeError, match=r"No constructor defined!"):
        cls()
