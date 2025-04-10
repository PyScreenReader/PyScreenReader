import PyScreenReader as psr
import pytest

BASE_METHOD_NAME_VIRTUAL_CONTAINER_WIDGET = (
    'addChild',
    'getChildren',
)


def test_abstract_class():
    with pytest.raises(TypeError):
        psr.VirtualContainerWidget()


def test_methods():
    definitions = vars(psr.VirtualContainerWidget)
    for method in BASE_METHOD_NAME_VIRTUAL_CONTAINER_WIDGET:
        assert method in definitions
