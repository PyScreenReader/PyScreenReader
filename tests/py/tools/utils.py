import inspect
from typing import List

import pytest
from PyScreenReader import psr


"""
All the base methods that the children of VirtualWidget should have.
"""
BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET = (
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
    "__repr__",
    "get_widget_name",
)


def assert_all_base_functions_exist(cls: type[psr.VirtualWidget]) -> None:
    """
    Check if all subclasses (including VirtualWidget) are inheriting the correct methods from VirtualWidget.

    :param cls: class to test
    """
    definitions = vars(cls)
    for method in BASE_METHOD_NAMES_IN_VIRTUAL_WIDGET:
        assert method in definitions, f"{method} should not exist in {cls}."


def assert_correct_inheritance(cls: type[psr.VirtualWidget], chain: List[type[psr.VirtualWidget]]) -> None:
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

def assert_abstract_class(cls: type[psr.VirtualWidget]) -> None:
    """
    Assert the given class is an abstract class

    :param cls: class
    """
    with pytest.raises(TypeError):
        cls()
