#pragma once

#include "../Primitives.h"

#include <cmath>

namespace fl
{

	template <typename T>
	static inline FL_CONSTEXPR T pi() { return static_cast<T>(3.1415926535897932384626433832795028841971L); }

	static const f32 PI32 = pi<f32>();
	static const f64 PI64 = pi<f64>();
	static const f128 PI128 = pi<f128>();

	template <typename T>
	static inline FL_CONSTEXPR T e() { return static_cast<T>(2.7182818284590452353602874713526624977572L); }

	static const f32 E32 = e<f32>();
	static const f64 E64 = e<f64>();
	static const f128 E128 = e<f128>();

	template <typename T>
	static inline FL_CONSTEXPR T toDegrees(T radians) { return radians / pi<T>() * static_cast<T>(180); }
	template <typename T>
	static inline FL_CONSTEXPR T toRadians(T degrees) { return degrees * pi<T>() / static_cast<T>(180); }

	template <typename T>
	static inline FL_CONSTEXPR T sin(T v) { return std::sin(v); }
	template <typename T>
	static inline FL_CONSTEXPR T cos(T v) { return std::cos(v); }
	template <typename T>
	static inline FL_CONSTEXPR T tan(T v) { return std::tan(v); }

	template <typename T>
	static inline FL_CONSTEXPR T asin(T v) { return std::asin(v); }
	template <typename T>
	static inline FL_CONSTEXPR T acos(T v) { return std::acos(v); }
	template <typename T>
	static inline FL_CONSTEXPR T atan(T v) { return std::atan(v); }
	template <typename T>
	static inline FL_CONSTEXPR T atan(T v0, T v1) { return std::atan2(v0, v1); }

	template <typename T>
	static inline FL_CONSTEXPR T pow(T b, T e) { return std::pow(b, e); }
	template <typename T>
	static inline FL_CONSTEXPR T sqrt(T v) { return std::sqrt(v); }
	template <typename T>
	static inline FL_CONSTEXPR T cbrt(T v) { return std::cbrt(v); }

	template <typename T>
	static inline FL_CONSTEXPR T abs(T v) { return a < 0 ? -a : a; }

	static inline FL_CONSTEXPR f32 abs(f32 v)
	{
		*reinterpret_cast<ui32 *>(&v) &= ~(1 << 31);
		return v;
	}

	static inline FL_CONSTEXPR f64 abs(f64 v)
	{
		*reinterpret_cast<ui64 *>(&v) &= ~(static_cast<ui64>(1) << 63);
		return v;
	}

	template <typename T>
	static inline FL_CONSTEXPR T min(T a, T b) { return a < b ? a : b; }
	template <typename T>
	static inline FL_CONSTEXPR T max(T a, T b) { return a > b ? a : b; }
	template <typename T>
	static inline FL_CONSTEXPR T clamp(T v, T min, T max) { return v < min ? min : (v > max ? max : v); }

	template <typename T>
	static inline FL_CONSTEXPR T floor(T v) { return std::floor(v); }
	template <typename T>
	static inline FL_CONSTEXPR T ceil(T v) { return std::ceil(v); }
	template <typename T>
	static inline FL_CONSTEXPR T round(T v) { return std::round(v); }
	template <typename T>
	static inline FL_CONSTEXPR T fract(T v) { return std::modf(v, &v); }

	template <typename T>
	static inline FL_CONSTEXPR T lerp(T a, T b, T x) { return (b - a) * x + a; }

	template <typename T>
	static inline FL_CONSTEXPR T copySign(T v, T sign) { return (sign / abs(sign)) * abs(v); }

}