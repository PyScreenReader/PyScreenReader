#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <string>
#include <functional>

namespace attribute_utils {
/**
 * Get attribute from AXUIElementRef safely
 *
 * @tparam T type of attribute value
 * @param element element to get attribute from
 * @param attr_name attribute name
 * @param value pointer to write the value to
 * @return if the operation is returning kAXErrorSuccess
 */
    template<typename T>
    bool SafeGetAttribute(AXUIElementRef element, CFStringRef attr_name, T *value) {
        CFTypeRef value_ref;
        AXError err = AXUIElementCopyAttributeValue(element, attr_name, &value_ref);
        if (err != kAXErrorSuccess) {
            return false;
        }

        *value = reinterpret_cast<T>(value_ref);
        return true;
    }

/**
 * Get std string from CFStringRef safely
 *
 * @param string_ref a CFStringRef
 * @param ptr the string value to write to
 * @return if the operation succeeded
 */
    bool ConvertCFStringToCPPString(CFStringRef string_ref, std::string &ptr);

/**
 * RAII-styled implementation of a Core Foundation styled pointer auto-manager
 * @tparam T
 */
    template<typename T>
    struct CFReleaser {
        void operator()(T obj) const {
            if (obj) {
                CFRelease(obj);
            }
        }
    };

    template<typename T>
    using CFRef = std::unique_ptr<std::remove_pointer_t<T>, CFReleaser<T>>;

/**
 * @brief Generic helper to get and convert AXUIElementRef attribute using RAII (CFRef)
 *
 * @tparam CFType the CoreFoundation type (e.g., CFStringRef, CFBooleanRef)
 * @tparam CppType the corresponding C++ type you want to pass into the setter
 *
 * @param element AXUIElementRef from which to fetch attribute
 * @param attribute Attribute name (e.g., kAXValueAttribute)
 * @param convert A function that converts CFType to CppType
 * @param setter A setter function that takes CppType
 * @return true if all steps succeeded
 */
    template<typename CFType, typename CppType>
    bool GetAXAttribute(
            AXUIElementRef element,
            CFStringRef attribute,
            const std::function<bool(CFType, CppType &)> &convert,
            const std::function<void(const CppType &)> &setter
    ) {
        CFRef<CFType> cf_value;
        CFType raw_value = nullptr;
        if (!SafeGetAttribute(element, attribute, &raw_value)) {
            return false;
        }
        cf_value.reset(raw_value);

        CppType cpp_value;
        if (!convert(cf_value.get(), cpp_value)) {
            return false;
        }

        setter(cpp_value);
        return true;
    }
}  // namespace attribute_utils

