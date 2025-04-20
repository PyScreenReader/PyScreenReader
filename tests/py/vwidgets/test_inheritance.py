import PyScreenReader as psr
import inspect


def test_virtual_button_widget_inheritance():
    assert inspect.getmro(psr.VirtualButtonWidget)[1] == psr.VirtualWidget


def test_virtual_root_widget_inheritance():
    assert inspect.getmro(psr.VirtualRootWidget)[1] == psr.VirtualContainerWidget
    assert inspect.getmro(psr.VirtualRootWidget)[2] == psr.VirtualWidget


def test_virtual_text_field_widget_inheritance():
    assert inspect.getmro(psr.VirtualTextFieldWidget)[1] == psr.VirtualWidget


def test_virtual_text_widget_inheritance():
    assert inspect.getmro(psr.VirtualTextWidget)[1] == psr.VirtualWidget


def test_virtual_container_widget_inheritance():
    assert inspect.getmro(psr.VirtualContainerWidget)[1] == psr.VirtualWidget


def test_virtual_menu_group_inheritance():
    assert inspect.getmro(psr.VirtualMenuGroupWidget)[1] == psr.VirtualContainerWidget
    assert inspect.getmro(psr.VirtualMenuGroupWidget)[2] == psr.VirtualWidget


def test_virtual_menu_item_inheritance():
    assert inspect.getmro(psr.VirtualMenuItemWidget)[1] == psr.VirtualWidget


def test_virtual_window_inheritance():
    assert inspect.getmro(psr.VirtualWindowWidget)[1] == psr.VirtualContainerWidget
    assert inspect.getmro(psr.VirtualWindowWidget)[2] == psr.VirtualWidget


def test_virtual_group_inheritance():
    assert inspect.getmro(psr.VirtualGroupWidget)[1] == psr.VirtualContainerWidget
    assert inspect.getmro(psr.VirtualGroupWidget)[2] == psr.VirtualWidget


def test_virtual_unknown_inheritance():
    assert inspect.getmro(psr.VirtualUnknownWidget)[1] == psr.VirtualContainerWidget
    assert inspect.getmro(psr.VirtualUnknownWidget)[2] == psr.VirtualWidget
