from PyScreenReader import VirtualWidget, ScreenReader
from collections import deque

from tests.py.tools.utils import assert_abstract_class, assert_all_base_functions_exist


def test_abstract_class():
    assert_abstract_class(VirtualWidget)


def test_base_methods():
    assert_all_base_functions_exist(VirtualWidget)

def test_screen_reader():
    screen_reader = ScreenReader()
    root = screen_reader.getVirtualWidgetTreeByPID("32476")

    if root is None:
        print("Failed to get widget tree.")
    else:
        print("\n----START----")
        queue = deque([(-1, root)])

        while queue:
            indent, curr = queue.pop()
            print(f"{'-' * indent} ({indent}) {curr}")

            if hasattr(curr, "get_children") and callable(curr.get_children):
                try:
                    children = curr.get_children()
                    for child in reversed(children):  # reversed for nicer DFS print order
                        queue.append((indent + 1, child))
                except Exception as e:
                    print(f"Error reading children: {e}")
