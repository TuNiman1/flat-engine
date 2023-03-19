#pragma once
#pragma warning(disable : 4251)

#include "Platform.h"
#include "Compiler.h"

extern "C" void flmain();

namespace fl
{

    extern void runtimeAssert(bool condition);
    extern void runtimeAssert(bool condition, const char *message);

}

#ifdef _DEBUG
#define FL_DEBUG
#else
#define FL_RELEASE
#endif

#define FL_ASSERT(condition) FL::runtimeAssert(condition)
#define FL_ASSERT_M(condition, message) FL::runtimeAssert(condition, message)
#define FL_STATIC_ASSERT(condition) static_assert(condition)

#ifdef FL_DEBUG
#define FL_DEBUG_ASSERT(condition) FL_ASSERT(condition)
#define FL_DEBUG_ASSERT_M(condition, message) FL_ASSERT_M(condition, message)
#define FL_RELEASE_ASSERT(condition)
#define FL_RELEASE_ASSERT_M(condition)
#else
#define FL_DEBUG_ASSERT(condition)
#define FL_DEBUG_ASSERT_M(condition, message)
#define FL_RELEASE_ASSERT(condition) FL_ASSERT(condition)
#define FL_RELEASE_ASSERT_M(condition, message) FL_ASSERT_M(condition, message)
#endif

#ifdef FL_PLATFORM_WINDOWS
#ifdef FL_DLL_EXPORT
#define FL_API __declspec(dllexport)
#elif defined(FL_DLL_IMPORT)
#define FL_API __declspec(dllimport)
#else
#define FL_API
#endif
#else
#define FL_API
#endif

#define FL_CONSTEXPR constexpr

#define FL_COPY_MEMORY(source, destination, size) memcpy(destination, source, size)

#define FL_ZERO_MEMORY(block, size) memset(block, 0, size)

#ifdef FL_VISUAL_C_PLUS_PLUS
#define FL_FORCE_INLINE __forceinline
#else
#define FL_FORCE_INLINE inline
#endif