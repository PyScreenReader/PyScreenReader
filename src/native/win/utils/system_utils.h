#pragma once
#include <uiautomationclient.h>
#include <string>

#include "include/vwidget/widgets/virtual_text_widget.h"
#include "src/native/win/utils/pattern_data.h"

namespace system_utils {

using namespace pattern_data;

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
std::unique_ptr<const T> ParseControlPatternToData(IUIAutomationElement* element);

template <>
std::unique_ptr<const TextPatternData> ParseControlPatternToData<TextPatternData>(
    IUIAutomationElement* element);

void ApplyData(std::unique_ptr<const TextPatternData> data,
               std::shared_ptr<VirtualTextWidget> widget);

}  // namespace system_utils
