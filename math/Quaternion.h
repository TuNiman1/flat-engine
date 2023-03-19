#pragma once

#include "Vector4.h"

namespace fl
{

	template <typename T>
	class Matrix3;
	template <typename T>
	class Matrix4;

	template <typename T>
	class Quaternion
	{
	public:
		T x;
		T y;
		T z;
		T w;

		inline FL_CONSTEXPR Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
		inline FL_CONSTEXPR Quaternion(const Vector3<T> &xyz, const T &w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		inline FL_CONSTEXPR Quaternion() : x(0), y(0), z(0), w(1) {}
		Quaternion(const Matrix3<T> &m);
		Quaternion(const Matrix4<T> &m);
		inline ~Quaternion() {}

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
		Quaternion<T> normalized() const
		{
			Quaternion<T> v = *this;
			v.normalize<T2>();
			return v;
		}

		inline Quaternion<T> normalized() const { return normalized<T>(); }

		inline FL_CONSTEXPR T dot(const Quaternion<T> &q) const { return x * q.x + y * q.y + z * q.z + w * q.w; }
		inline FL_CONSTEXPR Quaternion<T> conjugate() const { return Quaternion<T>(-x, -y, -z, w); }

		template <typename T2>
		inline FL_CONSTEXPR operator Quaternion<T2>() const { return Quaternion<T2>(static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z), static_cast<T2>(w)); }

		inline Vector3<T> xyz() const { return Vector3<T>(x, y, z); }
	};

	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator+(const Quaternion<T> &a, const Quaternion<T> &b) { return Quaternion<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator-(const Quaternion<T> &a, const Quaternion<T> &b) { return Quaternion<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator*(const Quaternion<T> &a, const Quaternion<T> &b) { return Quaternion<T>(a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y, a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x, a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w, a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z); }

	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator+(const Quaternion<T> &a, T b) { return Quaternion<T>(a.x, a.y, a.z, a.w + b); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator-(const Quaternion<T> &a, T b) { return Quaternion<T>(a.x, a.y, a.z, a.w - b); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator*(const Quaternion<T> &a, T b) { return Quaternion<T>(a.x * b, a.y * b, a.z * b, a.w * b); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator/(const Quaternion<T> &a, T b) { return Quaternion<T>(a.x / b, a.y / b, a.z / b, a.w / b); }

	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator+(T a, const Quaternion<T> &b) { return Quaternion<T>(b.x, b.y, b.z, a + b.w); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator-(T a, const Quaternion<T> &b) { return Quaternion<T>(-b.x, -b.y, -b.z, a - b.w); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator*(T a, const Quaternion<T> &b) { return Quaternion<T>(a * b.x, a * b.y, a * b.z, a * b.w); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> operator/(T a, const Quaternion<T> &b) { return Quaternion<T>(a / -b.x, a / -b.y, a / -b.z, a / b.w); }

	template <typename T>
	inline void operator+=(Quaternion<T> &a, const Quaternion<T> &b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
	}
	template <typename T>
	inline void operator-=(Quaternion<T> &a, const Quaternion<T> &b)
	{
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
	}
	template <typename T>
	inline void operator*=(Quaternion<T> &a, const Quaternion<T> &b) { a = a * b; }

	template <typename T>
	inline void operator+=(Quaternion<T> &a, T b) { a.w += b; }
	template <typename T>
	inline void operator-=(Quaternion<T> &a, T b) { a.w -= b; }
	template <typename T>
	inline void operator*=(Quaternion<T> &a, T b)
	{
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
	}

	template <typename T>
	inline FL_CONSTEXPR bool operator==(const Quaternion<T> &a, const Quaternion<T> &b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
	template <typename T>
	inline FL_CONSTEXPR bool operator!=(const Quaternion<T> &a, const Quaternion<T> &b) { return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w; }

	template <typename T, typename T2>
	inline FL_CONSTEXPR T2 length(const Quaternion<T> &v) { return v.length<T2>(); }
	template <typename T>
	inline FL_CONSTEXPR T length(const Quaternion<T> &v) { return v.length(); }
	template <typename T>
	inline FL_CONSTEXPR T squaredLength(const Quaternion<T> &v) { return v.squaredLength(); }

	template <typename T, typename T2>
	void normalize(Quaternion<T> &v) { v.normalize<T2>(); }
	template <typename T>
	inline void normalize(Quaternion<T> &v) { v.normalize(); }
	template <typename T, typename T2>
	Quaternion<T> normalized(const Quaternion<T> &v) { return v.normalized<T2>(); }
	template <typename T>
	inline Quaternion<T> normalized(const Quaternion<T> &v) { return v.normalized(); }

	template <typename T>
	inline FL_CONSTEXPR T dot(const Quaternion<T> &a, const Quaternion<T> &b) { return a.dot(b); }
	template <typename T>
	inline FL_CONSTEXPR Quaternion<T> conjugate(const Quaternion<T> &q) { return q.conjugate(); }

	template <typename T>
	static inline FL_CONSTEXPR T lerp(const Quaternion<T> &a, Quaternion<T> b, T x) { return (((a.dot(b) < static_cast<T>(0) ? -b : b) - a) * x + a).normalized(); }

	template <typename T>
	Quaternion<T> slerp(const Quaternion<T> &a, Quaternion<T> b, T x)
	{
		a.normalize();
		b.normalize();

		T cosTheta = a.dot(b);

		if (cosTheta < static_cast<T>(0))
		{
			b = -b;
			cosTheta = -cosTheta;
		}

		T theta = acos(cosTheta) * x;
		return a * cos(theta) + (b - a * dot).normalized() * sin(theta);
	}

}

#include "Quaternion.inl"