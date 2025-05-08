#include "include/api/screen_reader.h"

#include <stdexcept>

#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::shared_ptr<VirtualRootWidget> ScreenReader::GetVirtualWidgetTreeByPID(const std::string &pid) const {
    return screen_reader_impl_.GetVirtualWidgetTreeByPID(pid);
}

// TODO(#30) the linter suppression could be removed until the issue is implemented
// NOLINTBEGIN(readability-convert-member-functions-to-static)
std::shared_ptr<VirtualRootWidget> ScreenReader::GetVirtualWidgetTreeByTitle(const std::string &title) const {
    throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualRootWidget> ScreenReader::GetVirtualWidgetTreeByClassName(const std::string &class_name) const {
    throw std::logic_error("Not yet implemented");
}
// NOLINTEND(readability-convert-member-functions-to-static)

void BindScreenReader(py::module &module) {
    py::class_<ScreenReader>(module, "ScreenReader")
            .def(py::init())
            .def("getVirtualWidgetTreeByPID", &ScreenReader::GetVirtualWidgetTreeByPID, py::return_value_policy::take_ownership)
            .def("getVirtualWidgetTreeByTitle", &ScreenReader::GetVirtualWidgetTreeByTitle, py::return_value_policy::take_ownership)
            .def("getVirtualWidgetTreeByClassName", &ScreenReader::GetVirtualWidgetTreeByClassName, py::return_value_policy::take_ownership);
}

REGISTER_BINDING("ScreenReader", BindScreenReader, "VirtualWidget")
