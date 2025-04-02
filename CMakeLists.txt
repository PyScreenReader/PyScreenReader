cmake_minimum_required(VERSION 3.26)
project(PyScreenReader)

add_subdirectory(pybind11)
pybind11_add_module(PyScreenReader src/main.cpp)

set(CMAKE_CXX_STANDARD 11)

target_compile_definitions(PyScreenReader
        PRIVATE VERSION_INFO=${VERSION_INFO})