#include <stdexcept>
#include <pybind11/pybind11.h>

#include "include/api/screen_reader.h"
#include "src/bindings_registry.h"

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

void BindScreenReader(pybind11::module &module) {
  pybind11::class_<ScreenReader>(module, "ScreenReader")
      .def(pybind11::init())
      .def("getVirtualWidgetTreeByPID",
           &ScreenReader::GetVirtualWidgetTreeByPID,
           pybind11::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByTitle",
           &ScreenReader::GetVirtualWidgetTreeByTitle,
           pybind11::return_value_policy::take_ownership)
      .def("getVirtualWidgetTreeByClassName",
           &ScreenReader::GetVirtualWidgetTreeByClassName,
           pybind11::return_value_policy::take_ownership);
}

REGISTER_BINDING("ScreenReader", BindScreenReader, "VirtualWidget")
