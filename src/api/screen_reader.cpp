#include "include/api/screen_reader.h"

#include <stdexcept>

#include "src/bindings_registry.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByPID(const std::string &pid) const {
  return screen_reader_impl_.GetVirtualWidgetTreeByPID(pid);
}

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByTitle(const std::string &title) const {
  throw std::logic_error("Not yet implemented");
}

std::shared_ptr<VirtualWidget>
ScreenReader::GetVirtualWidgetTreeByClassName(
    const std::string &class_name) const {
  throw std::logic_error("Not yet implemented");
}

void BindScreenReader(py::module &module) {
  py::class_<ScreenReader>(module, "ScreenReader")
      .def(py::init())
      .def("getVirtualWidgetTreeByPID",
           &ScreenReader::GetVirtualWidgetTreeByPID,
           py::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByTitle",
           &ScreenReader::GetVirtualWidgetTreeByTitle,
           py::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByClassName",
           &ScreenReader::GetVirtualWidgetTreeByClassName,
           py::return_value_policy::take_ownership);
}

REGISTER_BINDING("ScreenReader", BindScreenReader, "VirtualWidget")
