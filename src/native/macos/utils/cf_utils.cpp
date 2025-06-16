#include "src/native/macos/utils/cf_utils.h"

std::optional<std::string> cf_utils::ToString(CFStringRef string_ref) {
  if (string_ref == nullptr)
    return std::nullopt;

  // Get utf8 encoded string
  const char* c_str = CFStringGetCStringPtr(string_ref, kCFStringEncodingUTF8);
  if (c_str != nullptr)
    return std::string(c_str);

  // CFStringGetCStringPtr might not return in unknown cases, CFStringGetCString is the fallback
  // https://developer.apple.com/documentation/corefoundation/cfstringgetcstringptr(_:_:)?language=objc

  // CFStringGetLength returns the number of utf-16 code pairs of characters
  CFIndex utf16_length = CFStringGetLength(string_ref);

  // utf8_length + 1 is the max length we should use (+1 for the space of the \0 termination)
  CFIndex max_utf8_length = CFStringGetMaximumSizeForEncoding(utf16_length, kCFStringEncodingUTF8) + 1;

  std::string res(max_utf8_length, '\0');
  if (!CFStringGetCString(string_ref, res.data(), max_utf8_length, kCFStringEncodingUTF8))
    return std::nullopt;

  // shrinks the size of string to match the actual size of the C string
  res.resize(std::strlen(res.c_str()));

  return res;
}
