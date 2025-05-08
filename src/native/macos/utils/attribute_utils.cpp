#include "src/native/macos/utils/attribute_utils.h"


bool attribute_utils::ConvertCFStringToCPPString(CFStringRef string_ref, std::string& ptr) {
    if (string_ref == nullptr) {
        return false;
    }
    const char *c_str = CFStringGetCStringPtr(string_ref, kCFStringEncodingUTF8);

    if (c_str != nullptr) {
        ptr = c_str;
        return true;
    }
    CFIndex length = CFStringGetLength(string_ref);
    char *buffer = new char[length + 1];

    if (CFStringGetCString(string_ref, buffer, length + 1, kCFStringEncodingUTF8) != 0U) {
        ptr = buffer;
        delete[] buffer;
        return true;
    }

    delete[] buffer;
    return false;

}