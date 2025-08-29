#pragma once
#include <uiautomationclient.h>
#include <string>

#include "include/vwidget/virtual_widget.h"

namespace system_utils {

std::string BSTRtoUTF8(BSTR bstr);

template <typename T>
bool ParseControlPattern(VirtualWidget& widget, IUIAutomationElement* element);

template<>
bool ParseControlPattern<ITextProvider>(VirtualWidget& widget, IUIAutomationElement* element);

} // system_utils

