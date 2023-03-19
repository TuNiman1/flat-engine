#pragma once

#include "math/FixedWidthBigInteger.h"

// Big integers

// 16 byte signed integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<16> i128;
// 32 byte signed integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<32> i256;
// 64 byte signed integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<64> i512;
// 128 byte signed integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<128> i1024;

// 16 byte unsigned integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<16, true> ui128;
// 32 byte unsigned integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<32, true> ui256;
// 64 byte unsigned integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<64, true> ui512;
// 128 byte unsigned integer type. Uses the FixedWidthBigInteger class, lower performance should be expected.
typedef fl::FixedWidthBigInteger<128, true> ui1024;

#include "util/String.h"
#include "math/Vector2.h"
#include "math/Vector3.h"
#include "math/Vector4.h"
#include "math/Matrix3.h"
#include "math/Matrix4.h"
#include "math/Quaternion.h"
#include "math/Transform.h"

// 2 dimensional vectors

typedef fl::Vector2<i8> i8v2;
typedef fl::Vector2<i16> i16v2;
typedef fl::Vector2<i32> i32v2;
typedef fl::Vector2<i64> i64v2;

typedef fl::Vector2<i8f> i8fv2;
typedef fl::Vector2<i16f> i16fv2;
typedef fl::Vector2<i32f> i32fv2;
typedef fl::Vector2<i64f> i64fv2;

typedef fl::Vector2<i8l> i8lv2;
typedef fl::Vector2<i16l> i16lv2;
typedef fl::Vector2<i32l> i32lv2;
typedef fl::Vector2<i64l> i64lv2;

typedef fl::Vector2<ui8> ui8v2;
typedef fl::Vector2<ui16> ui16v2;
typedef fl::Vector2<ui32> ui32v2;
typedef fl::Vector2<ui64> ui64v2;

typedef fl::Vector2<ui8f> ui8fv2;
typedef fl::Vector2<ui16f> ui16fv2;
typedef fl::Vector2<ui32f> ui32fv2;
typedef fl::Vector2<ui64f> ui64fv2;

typedef fl::Vector2<ui8l> ui8lv2;
typedef fl::Vector2<ui16l> ui16lv2;
typedef fl::Vector2<ui32l> ui32lv2;
typedef fl::Vector2<ui64l> ui64lv2;

typedef fl::Vector2<f32> f32v2;
typedef fl::Vector2<f64> f64v2;
typedef fl::Vector2<f128> f128v2;

template <>
struct std::hash<i32v2>
{
    size_t operator()(const i32v2 &v) const
    {
        return std::hash<i32>()(v.x) << 1 ^ std::hash<i32>()(v.y);
    }
};

// 3 dimensional vectors

typedef fl::Vector3<i8> i8v3;
typedef fl::Vector3<i16> i16v3;
typedef fl::Vector3<i32> i32v3;
typedef fl::Vector3<i64> i64v3;

typedef fl::Vector3<i8f> i8fv3;
typedef fl::Vector3<i16f> i16fv3;
typedef fl::Vector3<i32f> i32fv3;
typedef fl::Vector3<i64f> i64fv3;

typedef fl::Vector3<i8l> i8lv3;
typedef fl::Vector3<i16l> i16lv3;
typedef fl::Vector3<i32l> i32lv3;
typedef fl::Vector3<i64l> i64lv3;

typedef fl::Vector3<ui8> ui8v3;
typedef fl::Vector3<ui16> ui16v3;
typedef fl::Vector3<ui32> ui32v3;
typedef fl::Vector3<ui64> ui64v3;

typedef fl::Vector3<ui8f> ui8fv3;
typedef fl::Vector3<ui16f> ui16fv3;
typedef fl::Vector3<ui32f> ui32fv3;
typedef fl::Vector3<ui64f> ui64fv3;

typedef fl::Vector3<ui8l> ui8lv3;
typedef fl::Vector3<ui16l> ui16lv3;
typedef fl::Vector3<ui32l> ui32lv3;
typedef fl::Vector3<ui64l> ui64lv3;

typedef fl::Vector3<f32> f32v3;
typedef fl::Vector3<f64> f64v3;
typedef fl::Vector3<f128> f128v3;

template <>
struct std::hash<i32v3>
{
    size_t operator()(const i32v3 &v) const
    {
        return std::hash<i32>()(v.x) << 2 ^ std::hash<i32>()(v.y) << 1 ^ std::hash<i32>()(v.z);
    }
};

// 4 dimensional vectors

typedef fl::Vector4<i8> i8v4;
typedef fl::Vector4<i16> i16v4;
typedef fl::Vector4<i32> i32v4;
typedef fl::Vector4<i64> i64v4;

typedef fl::Vector4<i8f> i8fv4;
typedef fl::Vector4<i16f> i16fv4;
typedef fl::Vector4<i32f> i32fv4;
typedef fl::Vector4<i64f> i64fv4;

typedef fl::Vector4<i8l> i8lv4;
typedef fl::Vector4<i16l> i16lv4;
typedef fl::Vector4<i32l> i32lv4;
typedef fl::Vector4<i64l> i64lv4;

typedef fl::Vector4<ui8> ui8v4;
typedef fl::Vector4<ui16> ui16v4;
typedef fl::Vector4<ui32> ui32v4;
typedef fl::Vector4<ui64> ui64v4;

typedef fl::Vector4<ui8f> ui8fv4;
typedef fl::Vector4<ui16f> ui16fv4;
typedef fl::Vector4<ui32f> ui32fv4;
typedef fl::Vector4<ui64f> ui64fv4;

typedef fl::Vector4<ui8l> ui8lv4;
typedef fl::Vector4<ui16l> ui16lv4;
typedef fl::Vector4<ui32l> ui32lv4;
typedef fl::Vector4<ui64l> ui64lv4;

typedef fl::Vector4<f32> f32v4;
typedef fl::Vector4<f64> f64v4;
typedef fl::Vector4<f128> f128v4;

template <>
struct std::hash<i32v4>
{
    size_t operator()(const i32v4 &v) const
    {
        return std::hash<i32>()(v.x) << 3 ^ std::hash<i32>()(v.y) << 2 ^ std::hash<i32>()(v.z) << 1 ^ std::hash<i32>()(v.w);
    }
};

// 3x3 matrices

typedef fl::Matrix3<f32> f32m3;
typedef fl::Matrix3<f64> f64m3;
typedef fl::Matrix3<f128> f128m3;

// 4x4 matrices

typedef fl::Matrix4<f32> f32m4;
typedef fl::Matrix4<f64> f64m4;
typedef fl::Matrix4<f128> f128m4;

// Quaternions

typedef fl::Quaternion<f32> f32q;
typedef fl::Quaternion<f64> f64q;
typedef fl::Quaternion<f128> f128q;

// Transforms

typedef fl::Transform<f32> f32t;
typedef fl::Transform<f64> f64t;
typedef fl::Transform<f128> f128t;