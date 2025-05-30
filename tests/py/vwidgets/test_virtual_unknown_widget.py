import PyScreenReader as psr

BASE_METHOD_NAME_VIRTUAL_UNKNOWN_WIDGET = (
    "setClickable",
    "isClickable",
    "setNativeName",
    "getNativeName",
    "__init__",
)


def test_methods():
    definitions = vars(psr.VirtualUnknownWidget)
    for method in BASE_METHOD_NAME_VIRTUAL_UNKNOWN_WIDGET:
        assert method in definitions


def test_is_clickable():
    unknown_widget = psr.VirtualUnknownWidget()
    assert not unknown_widget.isClickable()
    unknown_widget.setClickable(True)
    assert unknown_widget.isClickable()


def test_native_name():
    unknown_widget = psr.VirtualUnknownWidget()
    unknown_widget.setNativeName("AXTree")
    assert unknown_widget.getNativeName() == "AXTree"
