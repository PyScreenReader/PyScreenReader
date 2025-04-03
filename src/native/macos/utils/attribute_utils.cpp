#include "native/macos/utils/attribute_utils.h"

template<typename T>
bool safeGetAttribute(AXUIElementRef element, CFStringRef attrName, T* value) {
    CFTypeRef valueRef;
    AXError err = AXUIElementCopyAttributeValue(element, attrName, &valueRef);
    if (err != kAXErrorSuccess) return false;

    *value = (T)valueRef;
    return true;
}

bool safeCFStringGetCString(CFStringRef stringRef, std::string& ptr) {
    if (stringRef == nullptr) return false;
    const char *cStr = CFStringGetCStringPtr(stringRef, kCFStringEncodingUTF8);

    if (cStr) {
        ptr = cStr;
        return true;
    } else {
        CFIndex length = CFStringGetLength(stringRef);
        char *buffer = new char[length + 1];

        if (CFStringGetCString(stringRef, buffer, length + 1, kCFStringEncodingUTF8)) {
            ptr = buffer;
            delete[] buffer;
            return true;
        }

        delete[] buffer;
        return false;
    }
}
