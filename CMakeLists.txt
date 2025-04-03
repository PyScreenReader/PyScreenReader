cmake_minimum_required(VERSION 3.26)
project(PyScreenReader)

add_subdirectory(pybind11)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp" "include/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)
pybind11_add_module(PyScreenReader ${SOURCE_FILES})

target_compile_definitions(PyScreenReader
        PRIVATE VERSION_INFO=${VERSION_INFO})

# Link CoreFoundation system library when compiling on MacOS
if(APPLE)
    target_link_libraries(PyScreenReader PRIVATE "-framework CoreFoundation")
endif()