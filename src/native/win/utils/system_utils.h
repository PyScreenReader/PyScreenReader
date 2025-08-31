#pragma once
#include <uiautomationclient.h>
#include <string>

#include "include/vwidget/virtual_widget.h"
#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"

namespace system_utils {

struct TextPatternData {
  std::string selected_text;
};

/**
 * Function for processing native windows strings into UTF-8 format
 *
 * @param bstr The BSTR to convert to UTF-8
 * @return A UTF-8 encoded string
 */
std::string BSTRtoUTF8(BSTR bstr);

/**
 * This template function is used to parse data based on the given Control Pattern Interface
 * for IUIAutomationElements which implement specific control patterns.
 *
 * @tparam T An IUnknown interface. The Control Pattern Interface we are extracting
 * @param element The IUIAutomationElement to parse
 * @return true on success, false otherwise
 */
template <typename T>
const T& ParseControlPatternToData(IUIAutomationElement* element);

template <>
const TextPatternData& ParseControlPatternToData<TextPatternData>(IUIAutomationElement* element);

void ApplyData(const TextPatternData& data, const std::shared_ptr<VirtualTextWidget>& widget);

}  // namespace system_utils
