import inspect
from typing import List

import pytest
from PyScreenReader import VirtualWidget

"""
All the base methods that the children of VirtualWidget should have.
"""
BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET = frozenset([
    "get_title_text",
    "get_help_text",
    "get_native_name",
    "get_x",
    "get_y",
    "get_width",
    "get_height",
    "is_visible",
    "is_focused",
    "get_parent",
    "get_child",
    "get_widget_name",
])


def assert_all_base_functions_exist(cls: type[VirtualWidget]) -> None:
    """
    Check if all subclasses (including VirtualWidget) are inheriting the correct methods from VirtualWidget.

    :param cls: class to test
    """
    definitions = vars(cls)
    for method in BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET:
        assert method in definitions, f"{method} should exist in {cls}."


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
