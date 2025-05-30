from collections import deque

import PyScreenReader as psr


def test_screen_reader():
    screen_reader = psr.ScreenReader()
    root = screen_reader.getVirtualWidgetTreeByPID("18080")

    if root is None:
        print("Failed to get widget tree.")
    else:
        queue = deque([(-1, root)])

        while queue:
            indent, curr = queue.pop()
            print(f"{'-' * indent} ({indent}) {curr}")

            if hasattr(curr, "getChildren") and callable(curr.getChildren):
                try:
                    children = curr.getChildren()
                    for child in reversed(children):  # reversed for nicer DFS print order
                        queue.append((indent + 1, child))
                except Exception as e:
                    print(f"Error reading children: {e}")
