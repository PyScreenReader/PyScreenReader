#pragma once
#include <uiautomationclient.h>
#include <string>

#include "include/vwidget/virtual_widget.h"

namespace system_utils {

std::string BSTRtoUTF8(BSTR bstr);

template <typename T>
bool ParseProvider(VirtualWidget& widget, IUIAutomationElement* element);

template<>
bool ParseProvider<ITextProvider>(VirtualWidget& widget, IUIAutomationElement* element);

} // system_utils

