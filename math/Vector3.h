#pragma once

#include "Vector2.h"

namespace fl
{

	template <typename T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;

		inline FL_CONSTEXPR Vector3(T v = static_cast<T>(0)) : x(v), y(v), z(v) {}
		inline FL_CONSTEXPR Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
		inline FL_CONSTEXPR Vector3(const Vector2<T> &xy, T z) : x(xy.x), y(xy.y), z(z) {}
		inline ~Vector3() {}

		template <typename T2>
		inline FL_CONSTEXPR T2 length() const { return sqrt(static_cast<T2>(squaredLength())); }
		inline FL_CONSTEXPR T length() const { return length<T>(); }
		inline FL_CONSTEXPR T squaredLength() const { return x * x + y * y + z * z; }

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
		Vector3<T> normalized() const
		{
			Vector3<T> v = *this;
			v.normalize<T2>();
			return v;
		}

		inline Vector3<T> normalized() const { return normalized<T>(); }

		inline FL_CONSTEXPR T dot(const Vector3<T> &v) const { return x * v.x + y * v.y + z * v.z; }
		inline FL_CONSTEXPR Vector3<T> cross(const Vector3<T> &v) const { return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
		inline FL_CONSTEXPR Vector3<T> min(const Vector3<T> &v) const { return Vector3<T>(min(v.x, x), min(v.y, y), min(v.z, z)); }
		inline FL_CONSTEXPR Vector3<T> max(const Vector3<T> &v) const { return Vector3<T>(max(v.x, x), max(v.y, y), max(v.z, z)); }

		template <typename T2>
		inline FL_CONSTEXPR operator Vector3<T2>() const { return Vector3<T2>(static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z)); }

		inline Vector2<T> xx() const { return Vector2<T>(x, x); }
		inline Vector2<T> xy() const { return Vector2<T>(x, y); }
		inline Vector2<T> xz() const { return Vector2<T>(x, z); }

		inline Vector2<T> yx() const { return Vector2<T>(y, x); }
		inline Vector2<T> yy() const { return Vector2<T>(y, y); }
		inline Vector2<T> yz() const { return Vector2<T>(y, z); }

		inline Vector2<T> zx() const { return Vector2<T>(z, x); }
		inline Vector2<T> zy() const { return Vector2<T>(z, y); }
		inline Vector2<T> zz() const { return Vector2<T>(z, z); }

		inline Vector3<T> xxx() const { return Vector3<T>(x, x, x); }
		inline Vector3<T> xyz() const { return Vector3<T>(x, y, z); }
		inline Vector3<T> yyy() const { return Vector3<T>(y, y, y); }
		inline Vector3<T> zzz() const { return Vector3<T>(z, z, z); }
		inline Vector3<T> zyx() const { return Vector3<T>(z, y, x); }
	};

	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b) { return Vector3<T>(a.x + b.x, a.y + b.y, a.z + b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b) { return Vector3<T>(a.x - b.x, a.y - b.y, a.z - b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator*(const Vector3<T> &a, const Vector3<T> &b) { return Vector3<T>(a.x * b.x, a.y * b.y, a.z * b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator/(const Vector3<T> &a, const Vector3<T> &b) { return Vector3<T>(a.x / b.x, a.y / b.y, a.z / b.z); }

	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator+(const Vector3<T> &a, T b) { return Vector3<T>(a.x + b, a.y + b, a.z + b); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator-(const Vector3<T> &a, T b) { return Vector3<T>(a.x - b, a.y - b, a.z - b); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator*(const Vector3<T> &a, T b) { return Vector3<T>(a.x * b, a.y * b, a.z * b); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator/(const Vector3<T> &a, T b) { return Vector3<T>(a.x / b, a.y / b, a.z / b); }

	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator+(T a, const Vector3<T> &b) { return Vector3<T>(a + b.x, a + b.y, a + b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator-(T a, const Vector3<T> &b) { return Vector3<T>(a - b.x, a - b.y, a - b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator*(T a, const Vector3<T> &b) { return Vector3<T>(a * b.x, a * b.y, a * b.z); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> operator/(T a, const Vector3<T> &b) { return Vector3<T>(a / b.x, a / b.y, a / b.z); }

	template <typename T>
	inline void operator+=(Vector3<T> &a, const Vector3<T> &b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
	}
	template <typename T>
	inline void operator-=(Vector3<T> &a, const Vector3<T> &b)
	{
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
	}
	template <typename T>
	inline void operator*=(Vector3<T> &a, const Vector3<T> &b)
	{
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
	}
	template <typename T>
	inline void operator/=(Vector3<T> &a, const Vector3<T> &b)
	{
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
	}

	template <typename T>
	inline void operator+=(Vector3<T> &a, T b)
	{
		a.x += b;
		a.y += b;
		a.z += b;
	}
	template <typename T>
	inline void operator-=(Vector3<T> &a, T b)
	{
		a.x -= b;
		a.y -= b;
		a.z -= b;
	}
	template <typename T>
	inline void operator*=(Vector3<T> &a, T b)
	{
		a.x *= b;
		a.y *= b;
		a.z *= b;
	}
	template <typename T>
	inline void operator/=(Vector3<T> &a, T b)
	{
		a.x /= b;
		a.y /= b;
		a.z /= b;
	}

	template <typename T>
	inline FL_CONSTEXPR bool operator==(const Vector3<T> &a, const Vector3<T> &b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
	template <typename T>
	inline FL_CONSTEXPR bool operator!=(const Vector3<T> &a, const Vector3<T> &b) { return a.x != b.x || a.y != b.y || a.z != b.z; }

	template <typename T, typename T2>
	inline FL_CONSTEXPR T2 length(const Vector3<T> &v) { return v.length<T2>(); }
	template <typename T>
	inline FL_CONSTEXPR T length(const Vector3<T> &v) { return v.length(); }
	template <typename T>
	inline FL_CONSTEXPR T squaredLength(const Vector3<T> &v) { return v.squaredLength(); }

	template <typename T, typename T2>
	void normalize(Vector3<T> &v) { v.normalize<T2>(); }
	template <typename T>
	inline void normalize(Vector3<T> &v) { v.normalize(); }
	template <typename T, typename T2>
	Vector3<T> normalized(const Vector3<T> &v) { return v.normalized<T2>(); }
	template <typename T>
	inline Vector3<T> normalized(const Vector3<T> &v) { return v.normalized(); }

	template <typename T>
	inline FL_CONSTEXPR T dot(const Vector3<T> &a, const Vector3<T> &b) { return a.dot(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> min(const Vector3<T> &a, const Vector3<T> &b) { return a.min(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector3<T> max(const Vector3<T> &a, const Vector3<T> &b) { return a.max(b); }

	template <typename T>
	static inline FL_CONSTEXPR T lerp(const Vector3<T> &a, const Vector3<T> &b, T x) { return (b - a) * x + a; }

}
