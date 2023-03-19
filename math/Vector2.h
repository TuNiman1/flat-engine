#pragma once

#include "Math.h"

namespace fl
{

	template <typename T>
	class Vector2
	{
	public:
		T x;
		T y;

		inline FL_CONSTEXPR Vector2(T v = static_cast<T>(0)) : x(v), y(v) {}
		inline FL_CONSTEXPR Vector2(T x, T y) : x(x), y(y) {}
		inline ~Vector2() {}

		template <typename T2>
		inline FL_CONSTEXPR T2 length() const { return sqrt(static_cast<T2>(squaredLength())); }
		inline FL_CONSTEXPR T length() const { return length<T>(); }
		inline FL_CONSTEXPR T squaredLength() const { return x * x + y * y; }

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
		Vector2<T> normalized() const
		{
			Vector2<T> v = *this;
			v.normalize<T2>();
			return v;
		}

		inline Vector2<T> normalized() const { return normalized<T>(); }

		template <typename T2>
		Vector2<T> rotate(T2 angle)
		{
			T2 s = sin(angle);
			T2 c = cos(angle);
			return Vector2<T>(static_cast<T>(c * x - s * y), static_cast<T>(c * y + s * x));
		}

		inline FL_CONSTEXPR T dot(const Vector2<T> &v) const { return x * v.x + y * v.y; }
		inline FL_CONSTEXPR Vector2<T> min(const Vector2<T> &v) const { return Vector2<T>(min(v.x, x), min(v.y, y)); }
		inline FL_CONSTEXPR Vector2<T> max(const Vector2<T> &v) const { return Vector2<T>(max(v.x, x), max(v.y, y)); }

		template <typename T2>
		inline FL_CONSTEXPR operator Vector2<T2>() const { return Vector2<T2>(static_cast<T2>(x), static_cast<T2>(y)); }

		inline Vector2<T> xx() const { return Vector2<T>(x, x); }
		inline Vector2<T> xy() const { return Vector2<T>(x, y); }

		inline Vector2<T> yx() const { return Vector2<T>(y, x); }
		inline Vector2<T> yy() const { return Vector2<T>(y, y); }
	};

	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator+(const Vector2<T> &a, const Vector2<T> &b) { return Vector2<T>(a.x + b.x, a.y + b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator-(const Vector2<T> &a, const Vector2<T> &b) { return Vector2<T>(a.x - b.x, a.y - b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator*(const Vector2<T> &a, const Vector2<T> &b) { return Vector2<T>(a.x * b.x, a.y * b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator/(const Vector2<T> &a, const Vector2<T> &b) { return Vector2<T>(a.x / b.x, a.y / b.y); }

	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator+(const Vector2<T> &a, T b) { return Vector2<T>(a.x + b, a.y + b); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator-(const Vector2<T> &a, T b) { return Vector2<T>(a.x - b, a.y - b); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator*(const Vector2<T> &a, T b) { return Vector2<T>(a.x * b, a.y * b); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator/(const Vector2<T> &a, T b) { return Vector2<T>(a.x / b, a.y / b); }

	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator+(T a, const Vector2<T> &b) { return Vector2<T>(a + b.x, a + b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator-(T a, const Vector2<T> &b) { return Vector2<T>(a - b.x, a - b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator*(T a, const Vector2<T> &b) { return Vector2<T>(a * b.x, a * b.y); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> operator/(T a, const Vector2<T> &b) { return Vector2<T>(a / b.x, a / b.y); }

	template <typename T>
	inline void operator+=(Vector2<T> &a, const Vector2<T> &b)
	{
		a.x += b.x;
		a.y += b.y;
	}
	template <typename T>
	inline void operator-=(Vector2<T> &a, const Vector2<T> &b)
	{
		a.x -= b.x;
		a.y -= b.y;
	}
	template <typename T>
	inline void operator*=(Vector2<T> &a, const Vector2<T> &b)
	{
		a.x *= b.x;
		a.y *= b.y;
	}
	template <typename T>
	inline void operator/=(Vector2<T> &a, const Vector2<T> &b)
	{
		a.x /= b.x;
		a.y /= b.y;
	}

	template <typename T>
	inline void operator+=(Vector2<T> &a, T b)
	{
		a.x += b;
		a.y += b;
	}
	template <typename T>
	inline void operator-=(Vector2<T> &a, T b)
	{
		a.x -= b;
		a.y -= b;
	}
	template <typename T>
	inline void operator*=(Vector2<T> &a, T b)
	{
		a.x *= b;
		a.y *= b;
	}
	template <typename T>
	inline void operator/=(Vector2<T> &a, T b)
	{
		a.x /= b;
		a.y /= b;
	}

	template <typename T>
	inline FL_CONSTEXPR bool operator==(const Vector2<T> &a, const Vector2<T> &b) { return a.x == b.x && a.y == b.y; }
	template <typename T>
	inline FL_CONSTEXPR bool operator!=(const Vector2<T> &a, const Vector2<T> &b) { return a.x != b.x || a.y != b.y; }

	template <typename T, typename T2>
	inline FL_CONSTEXPR T2 length(const Vector2<T> &v) { return v.length<T2>(); }
	template <typename T>
	inline FL_CONSTEXPR T length(const Vector2<T> &v) { return v.length(); }
	template <typename T>
	inline FL_CONSTEXPR T squaredLength(const Vector2<T> &v) { return v.squaredLength(); }

	template <typename T, typename T2>
	void normalize(Vector2<T> &v) { v.normalize<T2>(); }
	template <typename T>
	inline void normalize(Vector2<T> &v) { v.normalize(); }
	template <typename T, typename T2>
	Vector2<T> normalized(const Vector2<T> &v) { return v.normalized<T2>(); }
	template <typename T>
	inline Vector2<T> normalized(const Vector2<T> &v) { return v.normalized(); }

	template <typename T>
	inline FL_CONSTEXPR T dot(const Vector2<T> &a, const Vector2<T> &b) { return a.dot(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> min(const Vector2<T> &a, const Vector2<T> &b) { return a.min(b); }
	template <typename T>
	inline FL_CONSTEXPR Vector2<T> max(const Vector2<T> &a, const Vector2<T> &b) { return a.max(b); }

	template <typename T>
	static inline FL_CONSTEXPR T lerp(const Vector2<T> &a, const Vector2<T> &b, T x) { return (b - a) * x + a; }

}
