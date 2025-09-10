"""
A submodule containing screen reader APIs
"""
import PyScreenReader.virtual_widgets
from __future__ import annotations
__all__ = ['ScreenReader']
class ScreenReader:
    """
    
    ScreenReader provides access to virtual widget trees for applications identified by process ID.
    """
    def __init__(self) -> None:
        """
        Create a new ScreenReader instance.
        """
    def get_virtual_widget_tree_by_pid(self, pid: int) -> PyScreenReader.virtual_widgets.VirtualWidget:
        """
        Retrieve the virtual widget tree associated with the specified process ID (PID).
        
        :param pid: The process ID identifying the target application.
        :return: Shared pointer to the VirtualWidget corresponding to the given PID.
        """
