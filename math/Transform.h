#pragma once

#include "Quaternion.h"

namespace fl
{

	template <typename T>
	class Matrix3;

	template <typename T>
	class Transform
	{
	public:
		Quaternion<T> rotation;
		Vector3<T> origin;

		inline FL_CONSTEXPR Transform(const Quaternion<T> &rotation, const Vector3<T> &origin) : rotation(rotation), origin(origin) {}
		inline ~Transform() {}
	};

	template <typename T>
	inline FL_CONSTEXPR Transform<T> operator*(const Transform<T> &a, const Transform<T> &b) { return Transform<T>(a.rotation * b.rotation, a.origin + b.origin); }
	template <typename T>
	inline void operator*=(Transform<T> &a, const Transform<T> &b)
	{
		a.rotation *= b.rotation;
		a.origin += b.origin;
	}

	template <typename T>
	static inline FL_CONSTEXPR T lerp(const Transform<T> &a, const Transform<T> &b, T x) { return Transform<T>(slerp(a.rotation, b.rotation, x), lerp(a.origin, b.origin, x)); }

}