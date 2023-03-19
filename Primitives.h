#pragma once

#include <cstdint>

typedef const char *cString;

// Signed integer types.

// 1 byte
typedef int8_t i8;
// 2 bytes
typedef int16_t i16;
// 4 bytes
typedef int32_t i32;
// 8 bytes
typedef int64_t i64;

// Fastest signed integer types.

// At least 1 byte
typedef int_fast8_t i8f;
// At least 2 bytes
typedef int_fast16_t i16f;
// At least 4 bytes
typedef int_fast32_t i32f;
// At least 8 bytes
typedef int_fast64_t i64f;

// Smallest signed integer types.

// At least 1 byte
typedef int_least8_t i8l;
// At least 2 bytes
typedef int_least16_t i16l;
// At least 4 bytes
typedef int_least32_t i32l;
// At least 8 bytes
typedef int_fast64_t i64l;

// Unsigned integer types.

// 1 byte
typedef uint8_t ui8;
// 2 bytes
typedef uint16_t ui16;
// 4 bytes
typedef uint32_t ui32;
// 8 bytes
typedef uint64_t ui64;

// Fastest unsigned integer types.

// At least 1 byte
typedef uint_fast8_t ui8f;
// At least 2 bytes
typedef uint_fast16_t ui16f;
// At least 4 bytes
typedef uint_fast32_t ui32f;
// At lease 8 bytes
typedef uint_fast64_t ui64f;

// Smallest unsigned integer types.

// At least 1 byte
typedef uint_least8_t ui8l;
// At least 2 bytes
typedef uint_least16_t ui16l;
// At least 4 bytes
typedef uint_least32_t ui32l;
// At least 8 bytes
typedef uint_least64_t ui64l;

// Floating types

typedef float f32;

#ifdef FL_REQUIRE_F32
static_assert(sizeof(f32) == 4, "Floats have to be 32 bit since FL_REQUIRE_F32 is defined");
#endif

typedef double f64;
#ifdef FL_REQUIRE_F64
static_assert(sizeof(f64) == 8, "Doubles have to be 64 bit since FL_REQUIRE_F64 is defined");
#endif

typedef long double f128;
#ifdef FL_REQUIRE_f128
static_assert(sizeof(f128) == 16, "Long doubles have to be 128 bit since FL_REQUIRE_F128 is defined");
#endif