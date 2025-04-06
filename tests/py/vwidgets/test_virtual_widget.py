import PyScreenReader as psr
import pytest

BASE_METHOD_NAME_VIRTUAL_WIDGET = (
    'getX',
    'getY',
    'getTitleText',
    'getHelpText',
    'getWidth',
    'getHeight',
    'isVisible',
    'getParent',
    'setTitleText',
    'setHelpText',
    'setX',
    'setY',
    'setWidth',
    'setHeight',
    'setParent',
    'setVisible',
    '__repr__',
    'isClickable',
    'getWidgetName'
)


def test_abstract_class():
    with pytest.raises(TypeError):
        psr.VirtualWidget()


def test_methods():
    definitions = vars(psr.VirtualWidget)
    for method in BASE_METHOD_NAME_VIRTUAL_WIDGET:
        assert method in definitions
