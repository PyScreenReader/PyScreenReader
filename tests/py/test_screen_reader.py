import PyScreenReader as psr

def test_screen_reader():
    screen_reader = psr.ScreenReader()
    print(screen_reader.getVirtualWidgetTreeByPID("20880"))
