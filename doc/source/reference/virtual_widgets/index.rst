Virtual Widgets
=============

.. important::

   PyScreenReader is still under active development. APIs are subjects to change.

A Virtual Widget is an abstraction that represents a UI element in a platform-independent way. It typically captures semantic information such as:

- Role (e.g., button, text, image)
- State (e.g., focused, selected)
- Label or name
- Bounds or layout

This abstraction allows you to process or reason about UI content without needing the actual GUI framework.

.. toctree::
   :maxdepth: 1
   :caption: Virtual Widgets:

   virtual_widget
   numeric_value_widget
   virtual_button_widget
   virtual_group_widget
   virtual_menu_widget
   virtual_menu_item_widget
   virtual_progress_bar_widget
   virtual_scrollbar_widget
   virtual_slider_widget
   virtual_spinner_widget
   virtual_text_input_widget
   virtual_text_widget
   virtual_window_widget
   virtual_unknown_widget
