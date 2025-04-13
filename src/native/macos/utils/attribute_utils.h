#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <string>

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
bool safeGetAttribute(AXUIElementRef element, CFStringRef attrName, T* value) {
    CFTypeRef valueRef;
    AXError err = AXUIElementCopyAttributeValue(element, attrName, &valueRef);
    if (err != kAXErrorSuccess) return false;

    *value = (T)valueRef;
    return true;
}

/**
 * Get std string from CFStringRef safely
 *
 * @param stringRef a CFStringRef
 * @param ptr the string value to write to
 * @return if the operation succeeded
 */
bool safeCFStringGetCString(CFStringRef stringRef, std::string& ptr);


template<typename T>
struct CFReleaser {
    void operator()(T obj) const {
        if (obj) CFRelease(obj);
    }
};
template<typename T>
using CFRef = std::unique_ptr<std::remove_pointer_t<T>, CFReleaser<T>>;
