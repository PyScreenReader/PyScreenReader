#include "include/api/screen_reader.h"

#include <stdexcept>

#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::shared_ptr<VirtualRootWidget> ScreenReader::getVirtualWidgetTreeByPID(const std::string &pid) const {
    return screen_reader_impl_.getVirtualWidgetTreeByPID(pid);
}

std::shared_ptr<VirtualRootWidget> ScreenReader::getVirtualWidgetTreeByTitle(const std::string &title) const {
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReader::getVirtualWidgetTreeByClassName(const std::string &className) const {
    throw std::logic_error("Not yet implemented");
}

void bindScreenReader(py::module &m) {
    py::class_<ScreenReader>(m, "ScreenReader")
            .def(py::init())
            .def("getVirtualWidgetTreeByPID", &ScreenReader::getVirtualWidgetTreeByPID, py::return_value_policy::take_ownership)
            .def("getVirtualWidgetTreeByTitle", &ScreenReader::getVirtualWidgetTreeByTitle, py::return_value_policy::take_ownership)
            .def("getVirtualWidgetTreeByClassName", &ScreenReader::getVirtualWidgetTreeByClassName, py::return_value_policy::take_ownership);
}

REGISTER_BINDING("ScreenReader", bindScreenReader, "VirtualWidget")
