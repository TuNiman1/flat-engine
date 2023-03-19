#pragma once

#include "../Build.h"
#include "Quaternion.h"

namespace fl
{

	template <typename T>
	class Matrix3
	{
	private:
		inline FL_CONSTEXPR Matrix3(T v00, T v10, T v20, T v01, T v11, T v21, T v02, T v12, T v22) : m_v{v00, v01, v02, v10, v11, v12, v20, v21, v22} {}
		inline FL_CONSTEXPR Matrix3() {}

	public:
		inline ~Matrix3() {}

		static inline FL_CONSTEXPR Matrix3<T> identity() { return Matrix3<T>(1, 0, 0, 0, 1, 0, 0, 0, 1); }

		static inline FL_CONSTEXPR Matrix3<T> translation(T x, T y) { return Matrix3<T>(1, 0, x, 0, 1, y, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix3<T> translation(const Vector2<T> v) { return translation(v.x, v.y); }

		static inline FL_CONSTEXPR Matrix3<T> rotation(T angle) { return rotationZ(angle); }
		static inline FL_CONSTEXPR Matrix3<T> rotationX(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix3<T>(1, 0, 0, 0, c, -s, 0, s, c);
		}
		static inline FL_CONSTEXPR Matrix3<T> rotationY(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix3<T>(c, 0, s, 0, 1, 0, -s, 0, c);
		}
		static inline FL_CONSTEXPR Matrix3<T> rotationZ(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix3<T>(c, -s, 0, s, c, 0, 0, 0, 1);
		}
		static inline FL_CONSTEXPR Matrix3<T> rotation(const Quaternion<T> q)
		{
			const T l = q.squaredLength();
			const T s = l == static_cast<T>(0) ? static_cast<T>(0) : static_cast<T>(2) / l;

			const T wx = s * q.w * q.x;
			const T wy = s * q.w * q.y;
			const T wz = s * q.w * q.z;
			const T xx = s * q.x * q.x;
			const T xy = s * q.x * q.y;
			const T xz = s * q.x * q.z;
			const T yy = s * q.y * q.y;
			const T yz = s * q.y * q.z;
			const T zz = s * q.z * q.z;

			return Matrix3<T>(1 - (yy + zz), xy - wz, xz + wy, xy + wz, 1 - (xx + zz), yz - wx, xz - wy, yz + wx, 1 - (xx + yy));
		}

		static inline FL_CONSTEXPR Matrix3<T> scale(T x, T y) { return Matrix3<T>(x, 0, 0, 0, y, 0, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix3<T> scale(Vector2<T> v) { return scale(v.x, v.y); }

		static inline FL_CONSTEXPR Matrix3<T> ortho(T left, T right, T bottom, T top) { return Matrix3<T>(static_cast<T>(2) / (right - left), 0, -(right + left) / (right - left), 0, static_cast<T>(2) / (top - bottom), -(top + bottom) / (top - bottom), 0, 0, 1); }

		Matrix3<T> operator*(const Matrix3<T> &m)
		{
			Matrix3<T> result;
			for (ui8f x = 0; x < 3; x++)
			{
				for (ui8f y = 0; y < 3; y++)
				{
					result.set(x, y, get(x, static_cast<ui8f>(0)) * m.get(static_cast<ui8f>(0), y) + get(x, static_cast<ui8f>(1)) * m.get(static_cast<ui8f>(1), y) + get(x, static_cast<ui8f>(2)) * m.get(static_cast<ui8f>(2), y));
				}
			}
			return result;
		}

		template <typename T2>
		inline T get(T2 x, T2 y) const { return m_v[x * 3 + y]; }
		template <typename T2>
		inline void set(T2 x, T2 y, T v) { m_v[x * 3 + y] = v; }

		template <typename T2>
		inline FL_CONSTEXPR operator Matrix3<T2>() const { return Matrix3<T2>(static_cast<T2>(m_v[0]), static_cast<T2>(m_v[3]), static_cast<T2>(m_v[6]), static_cast<T2>(m_v[1]), static_cast<T2>(m_v[4]), static_cast<T2>(m_v[7]), static_cast<T2>(m_v[2]), static_cast<T2>(m_v[5]), static_cast<T2>(m_v[9])); }

		inline const T *getData() const { return m_v; }
		inline T *getPointer() { return m_v; }

	private:
		T m_v[9];
	};

	template <typename T>
	void operator*=(Matrix3<T> &a, const Matrix3<T> &b)
	{
		Matrix3<T> m = a * b;
		memcpy(a.m_v, m.m_v, sizeof(m_v));
	}

}