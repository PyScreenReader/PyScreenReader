# Quick Start

## Installation
Install PyScreenReader latest release from pip registries.
```shell
pip install PyScreenReader
```
> **PyScreenReader is still in active development.**  
> If installation via `pip` fails, it may be due to incompatibility with your system’s OS, architecture, or Python interpreter version.
> Please kindly help us to file a report [here](https://github.com/Lmh-java/PyScreenReader/issues).

## Example
In your Python script,
```python
from PyScreenReader import ScreenReader

# Create a screen reader instance
screen_reader = ScreenReader()
# Read the virtual widget tree by program's PID
root = screen_reader.get_virtual_widget_tree_by_pid("424242")
```

Virtual widgets (such as VirtualButtonWidget, etc.) are high-level abstractions of native system UI elements.
They are organized into a hierarchical structure — a virtual widget tree — where each node represents a single widget on the screen.

In the example above, the `root` variable refers to the root node of the widget tree of program with PID "424242".  
From there, you can navigate through its children and inspect each widget's properties, including:
- Control type
- Bounding rectangle
- Text content
- Focus state
- ...

Code snippet below shows an example of BFS that traverses every node.
```python
def print_tree(root: VirtualWidget) -> None:
    """Print a virtual widget tree using DFS.

    :param root: root of the virtual widget tree
    """
    node_stack = [(root, 0)]

    while node_stack:
        curr_node, indent = node_stack.pop()

        if curr_node is None:
            continue

        print(" " * (indent * 2) + str(curr_node))

        for child in reversed(curr_node.get_children()):
            node_stack.append((child, indent + 1))

# Pass in the root created above to print the entire widget tree
print_tree(root)
```

For more information, please refer to other pages in this documentation.
