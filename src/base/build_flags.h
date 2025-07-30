#pragma once

#if defined(__APPLE__)
#define MAC_OS 1
#elif defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN__)
#define WIN_OS 1
#endif