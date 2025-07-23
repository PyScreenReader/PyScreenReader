# VirtualWidget

A virtual representation of a UI widget, supporting hierarchical relationships and common widget attributes.

## Overview

`VirtualWidget` provides an abstraction for UI elements/widgets in Python, encapsulating their geometry, textual content, visibility, focus, and parent-child relationships. It can represent buttons, text inputs, and other UI components.

---

## Methods

### Title and Help Text
- Title text is generally the primary text information represented by a UI widget. For example, 
- Help text is the secondary text information contained by a UI widget. For example, the alt text of a widget, the role description 

#### get_title_text()
  
**Returns:** `str` — The primary text content of the widget.

#### set_title_text(title_text)
**Parameters:**
- `title_text` (`str`): The primary text content to set.  
  **Returns:** None

#### get_help_text()
  
**Returns:** `str` — Secondary/help text, such as tooltip.

#### set_help_text(help_text)
**Parameters:**
- `help_text` (`str`): The help text to set.  
  **Returns:** None

---

### Widget Identity

#### get_native_name()
**Returns:** `str` — The native UI widget name this virtual widget maps from.

#### set_native_name(native_name)
**Parameters:**
- `native_name` (`str`): The name to set.  
**Returns:** None

#### get_widget_name()
**Returns:** `str` — The current virtual widget name in UpperCamelCase.

---

### Geometry

#### get_x()
**Returns:** `int` — The X coordinate (top-left corner, screen origin).

#### set_x(x)
**Parameters:**
- `x` (`int`): The X coordinate to set.  
**Returns:** None

#### get_y()
**Returns:** `int` — The Y coordinate (top-left corner, screen origin).

#### set_y(y)
**Parameters:**
- `y` (`int`): The Y coordinate to set.  
**Returns:** None

#### get_width()
  
**Returns:** `int` — The width of the widget.

#### set_width(width)
**Parameters:**
- `width` (`int`): The width to set.  
  **Returns:** None

#### get_height()
  
**Returns:** `int` — The height of the widget.

#### set_height(height)
**Parameters:**
- `height` (`int`): The height to set.  
**Returns:** None

---

### State

#### is_visible()
  
**Returns:** `bool` — `True` if the widget is visible.

#### set_visible(visible)
**Parameters:**
- `visible` (`bool`): `True` if the widget should be visible, otherwise `False`.  
**Returns:** None

#### is_focused()
**Returns:** `bool` — `True` if the widget is focused.

#### set_focused(focused)
**Parameters:**
- `focused` (`bool`): `True` if the widget should be focused, otherwise `False`.  
**Returns:** None

---

### Hierarchy

#### get_parent()
**Returns:** `VirtualWidget` — The parent widget.

#### set_parent(parent)
**Parameters:**
- `parent` (`VirtualWidget`): The parent widget to set.  
**Returns:** None

#### get_child(index)
**Parameters:**
- `index` (`int`): The index of the child widget to return.  
**Returns:** `VirtualWidget` — The child widget at the given index.  
**Raises:** `IndexError` if the index is invalid.

#### add_child(child)
**Parameters:**
- `child` (`VirtualWidget`): The child widget to add.  
**Returns:** None  
**Note:** This does **not** set the child's parent automatically; call `set_parent` on the child widget to maintain hierarchy.

#### get_children()
**Returns:** `list[VirtualWidget]` — All child widgets.

---

### String Representation

#### __repr__()
**Returns:** `str` — Formatted string of the widget’s state.

#### __str__()
**Returns:** `str` — Formatted string of the widget’s state. Same return value as `__repr__()`

---
