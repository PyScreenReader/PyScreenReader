#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <optional>
#include <string>

namespace cf_utils {

/**
 * Covert CFStringRef to std::string safely
 *
 * @param string_ref a CFStringRef
 * @return if the operation succeeded
 */
std::optional<std::string> ToString(CFStringRef string_ref);

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
std::optional<std::string> GetAttribute(AXUIElementRef element, CFStringRef attr_name);

/**
 * A specialization of GetAttribute<T> for getting boolean attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a C++ bool of the attribute value or std::nullopt in error cases.
 */
template <>
std::optional<bool> GetAttribute(AXUIElementRef element, CFStringRef attr_name);

/**
 * A specialization of GetAttribute<T> for getting CFArrayRef attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a CFArrayRef value or std::nullopt in error cases.
 *
 * @note In std::nullopt cases, the resources will be managed by this function. However, in
 *       successful cases, caller should take the ownership of the return value.
 */
template <>
std::optional<CFArrayRef> GetAttribute(AXUIElementRef element, CFStringRef attr_name);

/**
 * A specialization of GetAttribute<T> for getting CGPoint attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a CGPoint value or std::nullopt in error cases.
 */
template <>
std::optional<CGPoint> GetAttribute(AXUIElementRef element, CFStringRef attr_name);

/**
 * A specialization of GetAttribute<T> for getting CGSize attribute from an AXUIElementRef.
 *
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @return a CGSize value or std::nullopt in error cases.
 */
template <>
std::optional<CGSize> GetAttribute(AXUIElementRef element, CFStringRef attr_name);

}  // namespace cf_utils
