
import PyScreenReader as psr

from tests.py.tools.constants import METHOD_NAMES_IN_VIRTUAL_WIDGET_SUBCLASSES


def assert_getters_setters(
        subclass: type[psr.VirtualWidget],
        true_widget_name: str,
        true_is_clickable: bool,
):
    ins = subclass()

    ins.setVisible(False)
    assert not ins.isVisible()
    ins.setVisible(True)
    assert ins.isVisible()

    ins.setX(10)
    ins.setY(20)
    ins.setWidth(1)
    ins.setHeight(2)
    assert ins.getX() == 10
    assert ins.getY() == 20
    assert ins.getWidth() == 1
    assert ins.getHeight() == 2

    ins.setTitleText("title text")
    assert ins.getTitleText() == "title text"
    ins.setHelpText("help text")
    assert ins.getHelpText() == "help text"

    assert ins.getWidgetName() == true_widget_name
    assert ins.isClickable() == true_is_clickable


def assert_method_definitions(subclass: type[psr.VirtualWidget]):
    definitions = vars(subclass)
    for method in METHOD_NAMES_IN_VIRTUAL_WIDGET_SUBCLASSES:
        assert method in definitions
