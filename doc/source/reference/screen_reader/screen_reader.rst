.. class:: ScreenReader

   ScreenReader provides access to virtual widget trees for applications identified by process ID.

   .. method:: __init__() -> None

   Create a new ScreenReader instance.

   .. method:: get_virtual_widget_tree_by_pid(pid) -> PyScreenReader.virtual_widgets.VirtualWidget

   Retrieve the virtual widget tree associated with the specified process ID (PID).

   :param pid: The process ID identifying the target application.
   :return: Shared pointer to the VirtualWidget corresponding to the given PID.
