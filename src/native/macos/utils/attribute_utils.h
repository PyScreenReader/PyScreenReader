#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <string>
#include <functional>

namespace AttributeUtils {
/**
 * Get attribute from AXUIElementRef safely
 *
 * @tparam T type of attribute value
 * @param element element to get attribute from
 * @param attrName attribute name
 * @param value pointer to write the value to
 * @return if the operation is returning kAXErrorSuccess
 */
    template<typename T>
    bool safeGetAttribute(AXUIElementRef element, CFStringRef attrName, T *value) {
        CFTypeRef valueRef;
        AXError err = AXUIElementCopyAttributeValue(element, attrName, &valueRef);
        if (err != kAXErrorSuccess) return false;

        *value = (T) valueRef;
        return true;
    }

/**
 * Get std string from CFStringRef safely
 *
 * @param stringRef a CFStringRef
 * @param ptr the string value to write to
 * @return if the operation succeeded
 */
    bool convertCFStringToCPPString(CFStringRef stringRef, std::string &ptr);

/**
 * RAII-styled implementation of a Core Foundation styled pointer auto-manager
 * @tparam T
 */
    template<typename T>
    struct CFReleaser {
        void operator()(T obj) const {
            if (obj) CFRelease(obj);
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
    bool getAXAttribute(
            AXUIElementRef element,
            CFStringRef attribute,
            const std::function<bool(CFType, CppType &)> &convert,
            const std::function<void(const CppType &)> &setter
    ) {
        CFRef<CFType> cfValue;
        CFType rawValue = nullptr;
        if (!safeGetAttribute(element, attribute, &rawValue)) return false;
        cfValue.reset(rawValue);

        CppType cppValue;
        if (!convert(cfValue.get(), cppValue)) return false;

        setter(cppValue);
        return true;
    }
}

