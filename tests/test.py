# Copyright (c) 2016 The Pybind Development Team. All rights reserved.
# Original license: https://github.com/pybind/cmake_example/blob/master/LICENSE

import PyScreenReader as m


def test_main():
    assert m.__version__ == "0.0.1"
    assert m.add(1, 2) == 3
    assert m.subtract(1, 2) == -1


test_main()
