"""
PyScreenReader - Inspect Python

Run ScreenReader from Python bindings:

    bazel run //tools:py_inspect -- --pid=[pid#]
"""

import argparse
from PyScreenReader import ScreenReader

def print_tree(root):
    node_stack = [(root, 0)]

    while node_stack:
        curr_node, indent = node_stack.pop()

        if curr_node is None:
            continue

        print(" " * (indent * 2) + str(curr_node))

        for child in reversed(curr_node.get_children()):
            node_stack.append((child, indent + 1))


def main():
    parser = argparse.ArgumentParser(description="Run ScreenReader from Python bindings")
    parser.add_argument('--pid', '-p', type=int, required=True, help='PID of the program')

    args = parser.parse_args()
    pid = args.pid
    print(f"Running py_inspect on PID: {pid}")

    screen_reader = ScreenReader()
    root = screen_reader.get_virtual_widget_tree_by_pid(str(pid))

    print_tree(root)


if __name__ == "__main__":
    main()
