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

template <>
std::optional<std::string> cf_utils::GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);
  if (err != kAXErrorSuccess)
    return std::nullopt;

  if (!value_ref || CFGetTypeID(value_ref) != CFStringGetTypeID()) {
    if (value_ref)
      CFRelease(value_ref);
    return std::nullopt;
  }

  const auto *string_ref = static_cast<CFStringRef>(value_ref);
  std::string result_str = cf_utils::ToString(string_ref);

  CFRelease(value_ref);
  string_ref = nullptr;

  return result_str;
}

template <>
std::optional<bool> cf_utils::GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);
  if (err != kAXErrorSuccess)
    return std::nullopt;
  if (!value_ref || CFGetTypeID(value_ref) != CFBooleanGetTypeID()) {
    if (value_ref)
      CFRelease(value_ref);
    return std::nullopt;
  }

  const auto *bool_ref = static_cast<CFBooleanRef>(value_ref);

  bool result_bool = (bool_ref == kCFBooleanTrue);
  CFRelease(value_ref);
  bool_ref = nullptr;

  return result_bool;
}

template <>
std::optional<CFArrayRef> cf_utils::GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);

  if (err != kAXErrorSuccess)
    return std::nullopt;

  if (!value_ref || CFGetTypeID(value_ref) != CFArrayGetTypeID()) {
    if (value_ref)
      CFRelease(value_ref);
    return std::nullopt;
  }

  const auto *array_ref = static_cast<CFArrayRef>(value_ref);
  return array_ref;
}

template <>
std::optional<CGPoint> cf_utils::GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);

  if (err != kAXErrorSuccess || !value_ref)
    return std::nullopt;

  if (CFGetTypeID(value_ref) != AXValueGetTypeID() || AXValueGetType(static_cast<AXValueRef>(value_ref)) != kAXValueTypeCGPoint) {
    CFRelease(value_ref);
    return std::nullopt;
  }

  CGPoint point_val;
  if (!AXValueGetValue(static_cast<AXValueRef>(value_ref), kAXValueTypeCGPoint, &point_val)) {
    CFRelease(value_ref);
    return std::nullopt;
  }

  CFRelease(value_ref);
  return point_val;
}


template <>
std::optional<CGSize> cf_utils::GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);

  if (err != kAXErrorSuccess || !value_ref)
    return std::nullopt;

  if (CFGetTypeID(value_ref) != AXValueGetTypeID() || AXValueGetType(static_cast<AXValueRef>(value_ref)) != kAXValueTypeCGSize) {
    CFRelease(value_ref);
    return std::nullopt;
  }

  CGSize size_value;
  if (!AXValueGetValue(static_cast<AXValueRef>(value_ref), kAXValueTypeCGSize, &size_value)) {
    CFRelease(value_ref);
    return std::nullopt;
  }

  CFRelease(value_ref);
  return size_value;
}
