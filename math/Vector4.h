#pragma once

#include "Vector3.h"

namespace fl
{

	template <typename T>
	class Vector4
	{
	public:
		T x;
		T y;
		T z;
		T w;

		inline FL_CONSTEXPR Vector4(T v = static_cast<T>(0)) : x(v), y(v), z(v), w(v) {}
		inline FL_CONSTEXPR Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
		inline FL_CONSTEXPR Vector4(const Vector3<T> &xyz, T w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		inline ~Vector4() {}

		template <typename T2>
		inline FL_CONSTEXPR T2 length() const { return sqrt(static_cast<T2>(squaredLength())); }
		inline FL_CONSTEXPR T length() const { return length<T>(); }
		inline FL_CONSTEXPR T squaredLength() const { return x * x + y * y + z * z + w * w; }

		template <typename T2>
		void normalize()
		{
			T2 l = length<T2>();
			if (l == static_cast<T2>(0))
				return;
			*this /= static_cast<T>(l);
		}

		inline void normalize() { normalize<T>(); }

		template <typename T2>
		Vector4<T> normalized() const
		{
			Vector4<T> v = *this;
			v.normalize<T2>();
			return v;
		}

		inline Vector4<T> normalized() const { return normalized<T>(); }

		inline FL_CONSTEXPR T dot(const Vector4<T> &v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
		inline FL_CONSTEXPR Vector4<T> min(const Vector4<T> &v) const { return Vector4<T>(min(v.x, x), min(v.y, y), min(v.z, z), min(v.w, w)); }
		inline FL_CONSTEXPR Vector4<T> max(const Vector4<T> &v) const { return Vector4<T>(max(v.x, x), max(v.y, y), max(v.z, z), max(v.w, w)); }

		template <typename T2>
		inline FL_CONSTEXPR operator Vector4<T2>() const { return Vector4<T2>(static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z), static_cast<T2>(w)); }

		inline Vector2<T> xx() const { return Vector2<T>(x, x); }
		inline Vector2<T> xy() const { return Vector2<T>(x, y); }
		inline Vector2<T> xz() const { return Vector2<T>(x, z); }
		inline Vector2<T> xw() const { return Vector2<T>(x, w); }

		inline Vector2<T> yx() const { return Vector2<T>(y, x); }
		inline Vector2<T> yy() const { return Vector2<T>(y, y); }
		inline Vector2<T> yz() const { return Vector2<T>(y, z); }
		inline Vector2<T> yw() const { return Vector2<T>(y, w); }

		inline Vector2<T> zx() const { return Vector2<T>(z, x); }
		inline Vector2<T> zy() const { return Vector2<T>(z, y); }
		inline Vector2<T> zz() const { return Vector2<T>(z, z); }
		inline Vector2<T> zw() const { return Vector2<T>(z, w); }

		inline Vector2<T> wx() const { return Vector2<T>(w, x); }
		inline Vector2<T> wy() const { return Vector2<T>(w, y); }
		inline Vector2<T> wz() const { return Vector2<T>(w, z); }
		inline Vector2<T> ww() const { return Vector2<T>(w, w); }

		inline Vector3<T> xxx() const { return Vector3<T>(x, x, x); }
		inline Vector3<T> xyz() const { return Vector3<T>(x, y, z); }
		inline Vector3<T> yyy() const { return Vector3<T>(y, y, y); }
		inline Vector3<T> zzz() const { return Vector3<T>(z, z, z); }
		inline Vector3<T> zyx() const { return Vector3<T>(z, y, x); }

		inline Vector4<T> xxxx() const { return Vector4<T>(x, x, x, x); }
		inline Vector4<T> xyzw() const { return Vector4<T>(x, y, z, w); }
		inline Vector4<T> yyyy() const { return Vector4<T>(y, y, y, y); }
		inline Vector4<T> zzzz() const { return Vector4<T>(z, z, z, z); }
		inline Vector4<T> wwww() const { return Vector4<T>(w, w, w, w); }
		inline Vector4<T> wxyz() const { return Vector4<T>(w, x, y, z); }
		inline Vector4<T> wzyx() const { return Vector4<T>(w, z, y, x); }
	};

	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator+(const Vector4<T> &a, const Vector4<T> &b) { return Vector4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator-(const Vector4<T> &a, const Vector4<T> &b) { return Vector4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator*(const Vector4<T> &a, const Vector4<T> &b) { return Vector4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator/(const Vector4<T> &a, const Vector4<T> &b) { return Vector4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }

	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator+(const Vector4<T> &a, T b) { return Vector4<T>(a.x + b, a.y + b, a.z + b, a.w + b); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator-(const Vector4<T> &a, T b) { return Vector4<T>(a.x - b, a.y - b, a.z - b, a.w - b); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator*(const Vector4<T> &a, T b) { return Vector4<T>(a.x * b, a.y * b, a.z * b, a.w * b); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator/(const Vector4<T> &a, T b) { return Vector4<T>(a.x / b, a.y / b, a.z / b, a.w / b); }

	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator+(T a, const Vector4<T> &b) { return Vector4<T>(a + b.x, a + b.y, a + b.z, a + b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator-(T a, const Vector4<T> &b) { return Vector4<T>(a - b.x, a - b.y, a - b.z, a - b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator*(T a, const Vector4<T> &b) { return Vector4<T>(a * b.x, a * b.y, a * b.z, a * b.w); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> operator/(T a, const Vector4<T> &b) { return Vector4<T>(a / b.x, a / b.y, a / b.z, a / b.w); }

	template <typename T>
	inline void operator+=(Vector4<T> &a, const Vector4<T> &b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
	}
	template <typename T>
	inline void operator-=(Vector4<T> &a, const Vector4<T> &b)
	{
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
	}
	template <typename T>
	inline void operator*=(Vector4<T> &a, const Vector4<T> &b)
	{
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
	}
	template <typename T>
	inline void operator/=(Vector4<T> &a, const Vector4<T> &b)
	{
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
	}

	template <typename T>
	inline void operator+=(Vector4<T> &a, T b)
	{
		a.x += b;
		a.y += b;
		a.z += b;
		a.w += b;
	}
	template <typename T>
	inline void operator-=(Vector4<T> &a, T b)
	{
		a.x -= b;
		a.y -= b;
		a.z -= b;
		a.w -= b;
	}
	template <typename T>
	inline void operator*=(Vector4<T> &a, T b)
	{
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
	}
	template <typename T>
	inline void operator/=(Vector4<T> &a, T b)
	{
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
	}

	template <typename T>
	inline FL_CONSTEXPR bool operator==(const Vector4<T> &a, const Vector4<T> &b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
	template <typename T>
	inline FL_CONSTEXPR bool operator!=(const Vector4<T> &a, const Vector4<T> &b) { return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w; }

	template <typename T, typename T2>
	inline FL_CONSTEXPR T2 length(const Vector4<T> &v) { return v.length<T2>(); }
	template <typename T>
	inline FL_CONSTEXPR T length(const Vector4<T> &v) { return v.length(); }
	template <typename T>
	inline FL_CONSTEXPR T squaredLength(const Vector4<T> &v) { return v.squaredLength(); }

	template <typename T, typename T2>
	void normalize(Vector4<T> &v) { v.normalize<T2>(); }
	template <typename T>
	inline void normalize(Vector4<T> &v) { v.normalize(); }
	template <typename T, typename T2>
	Vector4<T> normalized(const Vector4<T> &v) { return v.normalized<T2>(); }
	template <typename T>
	inline Vector4<T> normalized(const Vector4<T> &v) { return v.normalized(); }

	template <typename T>
	inline FL_CONSTEXPR T dot(const Vector4<T> &a, const Vector4<T> &b) { return a.dot(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> min(const Vector4<T> &a, const Vector4<T> &b) { return a.min(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector4<T> max(const Vector4<T> &a, const Vector4<T> &b) { return a.max(b); }

	template <typename T>
	static inline FL_CONSTEXPR T lerp(const Vector4<T> &a, const Vector4<T> &b, T x) { return (b - a) * x + a; }

}
