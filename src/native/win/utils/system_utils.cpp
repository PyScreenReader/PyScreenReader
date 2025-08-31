#include "system_utils.h"

#include <iostream>
#include <ostream>
#include <sstream>

#include "include/vwidget/widgets/virtual_text_input_widget.h"
#include "include/vwidget/widgets/virtual_text_widget.h"

namespace system_utils {

std::string BSTRtoUTF8(BSTR bstr) {
  int len = SysStringLen(bstr);
  // special case because a NULL BSTR is a valid zero-length BSTR,
  // but regular string functions would balk on it
  if (len == 0)
    return "";
  int size_needed = WideCharToMultiByte(CP_UTF8, 0, bstr, len, NULL, 0, NULL, NULL);
  std::string ret(size_needed, '\0');
  WideCharToMultiByte(CP_UTF8, 0, bstr, len, ret.data(), ret.size(), NULL, NULL);
  return ret;
}

template <>
const TextPatternData& ParseControlPatternToData<TextPatternData>(IUIAutomationElement* element) {
  IUIAutomationTextPattern* text_pattern = nullptr;
  TextPatternData pattern_data;
  if (FAILED(element->GetCurrentPattern(UIA_TextPatternId,
                                        reinterpret_cast<IUnknown**>(&text_pattern)))) {
    return std::move(pattern_data);
  }
  // Selected Text
  IUIAutomationTextRangeArray* selected_text_array = nullptr;
  if (!text_pattern || FAILED(text_pattern->GetSelection(&selected_text_array))) {
    return std::move(pattern_data);
  }

  int rangeCount = 0;
  selected_text_array->get_Length(&rangeCount);
  std::stringstream selected_text;
  IUIAutomationTextRange* text_range = nullptr;
  BSTR text = nullptr;
  for (int i = 0; i < rangeCount; i++) {
    if (SUCCEEDED(selected_text_array->GetElement(i, &text_range))) {
      // The -1 argument for GetText means to retrieve the entire range.
      if (SUCCEEDED(text_range->GetText(-1, &text)) && text) {
        selected_text << BSTRtoUTF8(text);
      }
      // Cleanup text and text_range
      SysFreeString(text);
      text = nullptr;
      if (text_range) {
        text_range->Release();
        text_range = nullptr;
      }
    }
  }
  pattern_data.selected_text =  selected_text.str();
  selected_text_array->Release();
  text_pattern->Release();
  return std::move(pattern_data);
}

void ApplyData(const TextPatternData& data, const std::shared_ptr<VirtualTextWidget>& widget) {
  widget->SetSelectedText(data.selected_text);
}

}  // namespace system_utils