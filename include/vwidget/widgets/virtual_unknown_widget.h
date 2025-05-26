#pragma once

#include "include/vwidget/virtual_container_widget.h"
#include <string>

class VirtualUnknownWidget : public VirtualContainerWidget {
public:
  VirtualUnknownWidget();
  std::string GetWidgetName() override;
  bool IsClickable() override;
  void SetClickable(bool new_clickable_value);
  const std::string &GetNativeName() const;
  void SetNativeName(const std::string &name);

private:
  bool is_clickable_;
  std::string native_name_;
};