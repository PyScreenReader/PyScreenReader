#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <functional>
#include <string>
#include <optional>

namespace cf_utils {
/**
 * Get attribute from an AXUIElementRef safely
 *
 * @tparam T type of attribute value
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return optional type of type T
 */
template <typename T>
std::optional<T> GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  return std::nullopt;
}

/**
 * A specialization of GetAttribute<T> for getting string attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a std::string of the attribute value or std::nullopt in error cases.
 */
template <>
std::optional<std::string> GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
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

/**
 * A specialization of GetAttribute<T> for getting boolean attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a C++ bool of the attribute value or std::nullopt in error cases.
 */
template <>
std::optional<bool> GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  CFTypeRef value_ref;
  AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);
  if (err != kAXErrorSuccess)
    return std::nullopt;

  if (!value_ref || CFGetTypeID(value_ref) != CFBooleanGetValue()) {
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

/**
 * A specialization of GetAttribute<T> for getting CFArrayRef attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a CFArrayRef of the attribute value or std::nullopt in error cases.
 */
template <>
std::optional<CFArrayRef> GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
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

/**
 * Covert CFStringRef to std::string safely
 *
 * @param string_ref a CFStringRef
 * @return if the operation succeeded
 */
std::optional<std::string> ToString(CFStringRef string_ref);
}  // namespace cf_utils
