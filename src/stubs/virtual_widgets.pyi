"""
A submodule containing virtual widgets definitions
"""
from __future__ import annotations
import typing
__all__ = ['HORIZONTAL', 'NumericValueWidget', 'Orientation', 'VERTICAL', 'VirtualButtonWidget', 'VirtualGroupWidget', 'VirtualMenuItemWidget', 'VirtualMenuWidget', 'VirtualProgressBarWidget', 'VirtualScrollbarWidget', 'VirtualSliderWidget', 'VirtualSpinnerWidget', 'VirtualTextInputWidget', 'VirtualTextWidget', 'VirtualUnknownWidget', 'VirtualWidget', 'VirtualWindowWidget']
class NumericValueWidget(VirtualWidget):
    """
    
    A widget that represents a numeric value with optional min/max bounds.
    """
    def get_max_value(self) -> int:
        """
        Get upper bound of the value.
        
        :return: Maximum value of the range.
        """
    def get_min_value(self) -> int:
        """
        Get lower bound of the value.
        
        :return: Minimum value of the range.
        """
    def get_value(self) -> int:
        """
        Get value contained in the widget.
        
        :return: Value contained in the widget.
        """
    def set_max_value(self, max_value: int) -> None:
        """
        Set upper bound of the value.
        
        :param max_value: Maximum value of the range.
        """
    def set_min_value(self, min_value: int) -> None:
        """
        Set lower bound of the value.
        
        :param min_value: Minimum value of the range.
        """
    def set_value(self, value: int) -> None:
        """
        Set value contained in the widget.
        
        :param value: Number value.
        """
class Orientation:
    """
    
    Enum representing the orientation of widgets.
    
    
    Members:
    
      HORIZONTAL : Horizontal orientation.
    
      VERTICAL : Vertical orientation.
    """
    HORIZONTAL: typing.ClassVar[Orientation]  # value = <Orientation.HORIZONTAL: 1>
    VERTICAL: typing.ClassVar[Orientation]  # value = <Orientation.VERTICAL: 0>
    __members__: typing.ClassVar[dict[str, Orientation]]  # value = {'HORIZONTAL': <Orientation.HORIZONTAL: 1>, 'VERTICAL': <Orientation.VERTICAL: 0>}
    def __eq__(self, other: typing.Any) -> bool:
        ...
    def __getstate__(self) -> int:
        ...
    def __hash__(self) -> int:
        ...
    def __index__(self) -> int:
        ...
    def __init__(self, value: int) -> None:
        ...
    def __int__(self) -> int:
        ...
    def __ne__(self, other: typing.Any) -> bool:
        ...
    def __repr__(self) -> str:
        ...
    def __setstate__(self, state: int) -> None:
        ...
    def __str__(self) -> str:
        ...
    @property
    def name(self) -> str:
        ...
    @property
    def value(self) -> int:
        ...
class VirtualButtonWidget(VirtualWidget):
    """
    
    A widget representing a button widget.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualButtonWidget instance.
        """
class VirtualGroupWidget(VirtualWidget):
    """
    
    A VirtualGroupWidget represents a container-like native widget
    that groups other widgets together in the accessibility tree.
    Examples include rows, columns, lists, or generic grouping elements.
    
    This abstraction models the hierarchical structure of the widget tree.
    A VirtualGroupWidget typically does not handle direct user interactions itself.
    If the native widget has specific interactive behaviors or functionalities,
    it should generally not be mapped to a VirtualGroupWidget.
    """
    def __init__(self) -> None:
        """
        Initialize a VirtualGroupWidget instance.
        """
class VirtualMenuItemWidget(VirtualWidget):
    """
    
    A widget representing a menu item widget.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualMenuItemWidget instance.
        """
class VirtualMenuWidget(VirtualWidget):
    """
    
    A widget representing a menu widget.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualMenuWidget instance.
        """
class VirtualProgressBarWidget(NumericValueWidget):
    """
    
    A widget representing a progress bar with a numeric value and orientation.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualProgressBarWidget instance.
        """
    def get_orientation(self) -> Orientation:
        """
        Get the current orientation of the progress bar widget.
        
        :return: Orientation of the widget.
        """
    def set_orientation(self, orientation: Orientation) -> None:
        """
        Set the current orientation of the progress bar widget.
        
        :param orientation: Orientation of the widget.
        """
class VirtualScrollbarWidget(NumericValueWidget):
    """
    
    A widget representing a scrollbar widget with numeric value and orientation.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualScrollbarWidget instance.
        """
    def get_orientation(self) -> Orientation:
        """
        Get the current orientation of the scrollbar widget.
        
        :return: Orientation of the widget.
        """
    def set_orientation(self, orientation: Orientation) -> None:
        """
        Set the current orientation of the scrollbar widget.
        
        :param orientation: Orientation of the widget.
        """
class VirtualSliderWidget(NumericValueWidget):
    """
    
    A widget representing a slider widget with numeric value and orientation.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualSliderWidget instance.
        """
    def get_orientation(self) -> Orientation:
        """
        Get the current orientation of the slider widget.
        
        :return: Orientation of the widget.
        """
    def set_orientation(self, orientation: Orientation) -> None:
        """
        Set the current orientation of the slider widget.
        
        :param orientation: Orientation of the widget.
        """
class VirtualSpinnerWidget(NumericValueWidget):
    """
    
    A widget representing a numeric spinner widget.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualSpinnerWidget instance.
        """
class VirtualTextInputWidget(VirtualWidget):
    """
    
    A widget representing a text input field or text area.
    
    Provides functionality for selection, cursor insertion point, and text area mode.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualTextInputWidget instance.
        """
    def get_insertion_point(self) -> int:
        """
        Get the current cursor location in the text input, represented by an index starting at 0.
        
        For example, in "A|BCDEFG", this function returns 1.
        
        :return: Current cursor index.
        """
    def get_selected_text(self) -> str:
        """
        Get the currently selected text in the input field.
        
        :return: Selected text.
        """
    def is_text_area(self) -> bool:
        """
        Check if the current input widget is a text area.
        
        :return: True if it's a text area, otherwise False.
        """
    def set_insertion_point(self, insertion_point: int) -> None:
        """
        Set the current cursor location index in the text input.
        
        See also: get_insertion_point()
        
        :param insertion_point: Index starting from 0.
        """
    def set_is_text_area(self, is_text_area: bool) -> None:
        """
        Set whether the input widget is a text area.
        
        :param is_text_area: True if it's a text area, otherwise False.
        """
    def set_selected_text(self, selected_text: str) -> None:
        """
        Set the currently selected text in the input field.
        
        :param selected_text: Selected text string.
        """
class VirtualTextWidget(VirtualWidget):
    """
    
    A widget representing static text content with selectable regions.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualTextWidget instance.
        """
    def get_selected_text(self) -> str:
        """
        Get the cursor-selected text in the static text widget.
        
        :return: Selected text.
        """
    def set_selected_text(self, selected_text: str) -> None:
        """
        Set the cursor-selected text in the static text widget.
        
        :param selected_text: Selected text string.
        """
class VirtualUnknownWidget(VirtualWidget):
    """
    
    A virtual widget used as a fallback when no proper mapping exists from the native system widget.
    
    This widget indicates that PyScreenReader cannot find a corresponding virtual widget
    to represent the native widget.
    """
    def __init__(self) -> None:
        """
        Initialize a VirtualUnknownWidget instance.
        """
class VirtualWidget:
    """
    
    Represents a virtual UI widget.
    
    This class provides an abstraction for a UI widget, supporting properties such as text, coordinates,
    dimensions, visibility, focus state, and parent/child relationships.
    """
    def __repr__(self) -> str:
        ...
    def __str__(self) -> str:
        ...
    def add_child(self, child: VirtualWidget) -> None:
        """
        Add a child widget to this widget.
        
        Note: This does not automatically set the child widget's parent. To preserve tree structure,
        you should also call set_parent() on the child widget to assign this widget as its parent.
        
        :param child: Child widget.
        """
    def get_child(self, index: int) -> VirtualWidget:
        """
        Get the child widget at the given index (starting from 0).
        
        Throws an out_of_range exception if there are not that many children.
        
        :param index: Index of the child widget.
        :return: Child widget at the given index.
        """
    def get_children(self) -> list[VirtualWidget]:
        """
        Get all children of this widget in the tree.
        
        :return: List of all children widgets.
        """
    def get_height(self) -> int:
        """
        Get the height of the current widget.
        
        :return: Height of the widget.
        """
    def get_help_text(self) -> str:
        """
        Get help text.
        
        Help text is generally the secondary text content in a widget.
        When you hover the cursor over widgets, if a tooltip pops up,
        the tooltip content will be considered a help text.
        
        :return: Help text.
        """
    def get_native_name(self) -> str:
        """
        Get name of the native widget this virtual widget is mapped from.
        
        :return: Native widget name.
        """
    def get_parent(self) -> VirtualWidget:
        """
        Get the parent widget of the current widget.
        
        :return: Parent widget.
        """
    def get_title_text(self) -> str:
        """
        Get title text.
        
        Title text is a string that represents the primary text content of the widget.
        - It can be the content string on the button, which says "Click me"
        - It can be the string that a text input is displaying (if any)
        
        :return: Title text string.
        """
    def get_widget_name(self) -> str:
        """
        Get the name of the current virtual widget in UpperCamelCase.
        
        Examples: "VirtualButtonWidget", "VirtualTextWidget", etc.
        
        :return: Current virtual widget name.
        """
    def get_width(self) -> int:
        """
        Get the width of the current widget.
        
        :return: Width of the widget.
        """
    def get_x(self) -> int:
        """
        Get the X coordinate of the top-left corner of the widget relative to the screen.
        
        The top-left corner of the screen is considered the origin.
        
        :return: X coordinate.
        """
    def get_y(self) -> int:
        """
        Get the Y coordinate of the top-left corner of the widget relative to the screen.
        
        The top-left corner of the screen is considered the origin.
        
        :return: Y coordinate.
        """
    def is_focused(self) -> bool:
        """
        Get whether the current widget is focused.
        
        :return: True if focused, False otherwise.
        """
    def is_visible(self) -> bool:
        """
        Get whether the current widget is visible to the user.
        
        :return: True if visible, False otherwise.
        """
    def set_focused(self, focused: bool) -> None:
        """
        Set whether the current widget is focused.
        
        :param focused: True if focused, False otherwise.
        """
    def set_height(self, height: int) -> None:
        """
        Set the height of the current widget.
        
        :param height: Height of the widget.
        """
    def set_help_text(self, help_text: str) -> None:
        """
        Set help text.
        
        See also: get_help_text()
        
        :param help_text: Help text string.
        """
    def set_native_name(self, native_name: str) -> None:
        """
        Set native widget name.
        
        See also: get_native_name()
        
        :param native_name: Name of the native widget this virtual widget is mapped from.
        """
    def set_parent(self, parent: VirtualWidget) -> None:
        """
        Set the parent widget of the current widget.
        
        :param parent: Parent widget.
        """
    def set_title_text(self, title_text: str) -> None:
        """
        Set title text.
        
        See also: get_title_text()
        
        :param title_text: Title text string.
        """
    def set_visible(self, visible: bool) -> None:
        """
        Set whether the current widget is visible to the user.
        
        :param visible: True if visible, False otherwise.
        """
    def set_width(self, width: int) -> None:
        """
        Set the width of the current widget.
        
        :param width: Width of the widget.
        """
    def set_x(self, x_coord: int) -> None:
        """
        Set the X coordinate of the top-left corner of the widget.
        
        :param x_coord: X coordinate.
        """
    def set_y(self, y_coord: int) -> None:
        """
        Set the Y coordinate of the top-left corner of the widget.
        
        :param y_coord: Y coordinate.
        """
class VirtualWindowWidget(VirtualWidget):
    """
    
    A widget representing a window, which can be modal or non-modal.
    """
    def __init__(self) -> None:
        """
        Create a new VirtualWindowWidget instance.
        """
    def is_modal(self) -> bool:
        """
        Check if the current window is a modal.
        
        Depending on the native system, a "modal" generally means a pop-up window that
        appears on top of its main content and blocks user interaction with the rest of the UI
        until the user completes specific actions or dismisses it.
        
        :return: True if the window is modal, otherwise False.
        """
    def set_is_modal(self, is_modal: bool) -> None:
        """
        Set whether the current window is a modal.
        
        :param is_modal: True if the window is modal, otherwise False.
        """
HORIZONTAL: Orientation  # value = <Orientation.HORIZONTAL: 1>
VERTICAL: Orientation  # value = <Orientation.VERTICAL: 0>
