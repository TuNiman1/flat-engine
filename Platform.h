// Platforms

#pragma once

#if defined(_WIN64)
#define FL_PLATFORM_WINDOWS_64
#define FL_ENVIRONMENT_64

#elif defined(_WIN32)
#define FL_PLATFORM_WINDOWS_32
#define FL_ENVIRONMENT_32

#elif defined(__APPLE__) || defined(__MACH__)
#define FL_PLATFORM_MAC_OS

#elif defined(__linux__)
#define FL_PLATFORM_LINUX

#elif defined(__unix) || defined(__unix__)
#define FL_PLATFORM_UNIX

#else
#define FL_PLATFORM_UNKNOWN

#endif

#if defined(FL_PLATFORM_WINDOWS_32) || defined(FL_PLATFORM_WINDOWS_64)
#define FL_PLATFORM_WINDOWS

#endif