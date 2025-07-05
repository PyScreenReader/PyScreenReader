#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <optional>
#include <stdexcept>
#include <string>
#include <typeinfo>

/**
 * cf_utils is a collection of helper functions that handles
 * CoreFoundation(CF) data structures conversions. Importantly,
 * cf_utils acts as a bridge between C++ data models (std::string, bool, etc.)
 * and CoreFoundation data models (CFStringRef, CFArrayRef, etc.)
 * https://developer.apple.com/documentation/corefoundation?language=objc
 */
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
 * @return optional type of T
 * @note This generalized function is not implemented, please use the specializations defined below.
 */
template <typename T>
std::optional<T> GetAttribute(AXUIElementRef element, CFStringRef attr_name) {
  throw std::logic_error("Type `" + std::string(typeid(T).name()) +
                         "` is not supported by GetAttribute<T>.");
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
