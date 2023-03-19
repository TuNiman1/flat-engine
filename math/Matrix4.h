#pragma once

#include "../Build.h"
#include "Transform.h"

namespace fl
{

	template <typename T>
	class Matrix4
	{
	private:
		inline FL_CONSTEXPR Matrix4(T v00, T v10, T v20, T v30, T v01, T v11, T v21, T v31, T v02, T v12, T v22, T v32, T v03, T v13, T v23, T v33) : m_v{v00, v01, v02, v03, v10, v11, v12, v13, v20, v21, v22, v23, v30, v31, v32, v33} {}
		inline FL_CONSTEXPR Matrix4() {}

	public:
		inline ~Matrix4() {}

		static inline FL_CONSTEXPR Matrix4<T> identity() { return Matrix4<T>(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }

		static inline FL_CONSTEXPR Matrix4<T> translation(T x, T y, T z) { return Matrix4<T>(1, 0, 0, x, 0, 1, 0, y, 0, 0, 1, z, 0, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix4<T> translation(const Vector3<T> &v) { return translation(v.x, v.y, v.z); }

		static inline FL_CONSTEXPR Matrix4<T> rotationX(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix4<T>(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
		}
		static inline FL_CONSTEXPR Matrix4<T> rotationY(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix4<T>(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
		}
		static inline FL_CONSTEXPR Matrix4<T> rotationZ(T angle)
		{
			const T s = sin(angle);
			const T c = cos(angle);
			return Matrix4<T>(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		}
		static inline FL_CONSTEXPR Matrix4<T> rotation(const Quaternion<T> q)
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

			return Matrix4<T>(1 - (yy + zz), xy - wz, xz + wy, 0, xy + wz, 1 - (xx + zz), yz - wx, 0, xz - wy, yz + wx, 1 - (xx + yy), 0, 0, 0, 0, 1);
		}

		static inline FL_CONSTEXPR Matrix4<T> scale(T x, T y, T z) { return Matrix4<T>(x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix4<T> scale(const Vector3<T> &v) { return scale(v.x, v.y, v.z); }

		static inline FL_CONSTEXPR Matrix4<T> transformation(const Transform<T> &v) { return translation(v.origin) * rotation(v.rotation); }

		static inline FL_CONSTEXPR Matrix4<T> lookat(const Vector3<T> &x, const Vector3<T> &y, const Vector3<T> &z) { return Matrix4<T>(x.x, y.x, z.x, 0, y.x, y.y, y.z, 0, z.x, z.y, z.z, 0, 0, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix4<T> ortho(T left, T right, T bottom, T top, T near, T far) { return Matrix4<T>(static_cast<T>(2) / (right - left), 0, 0, -(right + left) / (right - left), 0, static_cast<T>(2) / (top - bottom), 0, -(top + bottom) / (top - bottom), 0, 0, static_cast<T>(2) / (far - near), -(far + near) / (far - near), 0, 0, 0, 1); }
		static inline FL_CONSTEXPR Matrix4<T> perspective(T aspect, T fov, T near, T far)
		{
			const T t = tan(toRadians(fov) / static_cast<T>(2));
			return Matrix4<T>(static_cast<T>(1) / (t * aspect), 0, 0, 0, 0, static_cast<T>(1) / t, 0, 0, 0, 0, -(far + near) / (far - near), -(static_cast<T>(2) * far * near) / (far - near), 0, 0, static_cast<T>(-1), 0);
		}

		static bool Matrix4<T>::inverse(const Matrix4<T> &m, Matrix4<T> &result)
		{
			Matrix4<T> inv;

			inv.m_v[0] = m.m_v[5] * m.m_v[10] * m.m_v[15] - m.m_v[5] * m.m_v[11] * m.m_v[14] - m.m_v[9] * m.m_v[6] * m.m_v[15] + m.m_v[9] * m.m_v[7] * m.m_v[14] + m.m_v[13] * m.m_v[6] * m.m_v[11] - m.m_v[13] * m.m_v[7] * m.m_v[10];
			inv.m_v[4] = -m.m_v[4] * m.m_v[10] * m.m_v[15] + m.m_v[4] * m.m_v[11] * m.m_v[14] + m.m_v[8] * m.m_v[6] * m.m_v[15] - m.m_v[8] * m.m_v[7] * m.m_v[14] - m.m_v[12] * m.m_v[6] * m.m_v[11] + m.m_v[12] * m.m_v[7] * m.m_v[10];
			inv.m_v[8] = m.m_v[4] * m.m_v[9] * m.m_v[15] - m.m_v[4] * m.m_v[11] * m.m_v[13] - m.m_v[8] * m.m_v[5] * m.m_v[15] + m.m_v[8] * m.m_v[7] * m.m_v[13] + m.m_v[12] * m.m_v[5] * m.m_v[11] - m.m_v[12] * m.m_v[7] * m.m_v[9];
			inv.m_v[12] = -m.m_v[4] * m.m_v[9] * m.m_v[14] + m.m_v[4] * m.m_v[10] * m.m_v[13] + m.m_v[8] * m.m_v[5] * m.m_v[14] - m.m_v[8] * m.m_v[6] * m.m_v[13] - m.m_v[12] * m.m_v[5] * m.m_v[10] + m.m_v[12] * m.m_v[6] * m.m_v[9];
			inv.m_v[1] = -m.m_v[1] * m.m_v[10] * m.m_v[15] + m.m_v[1] * m.m_v[11] * m.m_v[14] + m.m_v[9] * m.m_v[2] * m.m_v[15] - m.m_v[9] * m.m_v[3] * m.m_v[14] - m.m_v[13] * m.m_v[2] * m.m_v[11] + m.m_v[13] * m.m_v[3] * m.m_v[10];
			inv.m_v[5] = m.m_v[0] * m.m_v[10] * m.m_v[15] - m.m_v[0] * m.m_v[11] * m.m_v[14] - m.m_v[8] * m.m_v[2] * m.m_v[15] + m.m_v[8] * m.m_v[3] * m.m_v[14] + m.m_v[12] * m.m_v[2] * m.m_v[11] - m.m_v[12] * m.m_v[3] * m.m_v[10];
			inv.m_v[9] = -m.m_v[0] * m.m_v[9] * m.m_v[15] + m.m_v[0] * m.m_v[11] * m.m_v[13] + m.m_v[8] * m.m_v[1] * m.m_v[15] - m.m_v[8] * m.m_v[3] * m.m_v[13] - m.m_v[12] * m.m_v[1] * m.m_v[11] + m.m_v[12] * m.m_v[3] * m.m_v[9];
			inv.m_v[13] = m.m_v[0] * m.m_v[9] * m.m_v[14] - m.m_v[0] * m.m_v[10] * m.m_v[13] - m.m_v[8] * m.m_v[1] * m.m_v[14] + m.m_v[8] * m.m_v[2] * m.m_v[13] + m.m_v[12] * m.m_v[1] * m.m_v[10] - m.m_v[12] * m.m_v[2] * m.m_v[9];
			inv.m_v[2] = m.m_v[1] * m.m_v[6] * m.m_v[15] - m.m_v[1] * m.m_v[7] * m.m_v[14] - m.m_v[5] * m.m_v[2] * m.m_v[15] + m.m_v[5] * m.m_v[3] * m.m_v[14] + m.m_v[13] * m.m_v[2] * m.m_v[7] - m.m_v[13] * m.m_v[3] * m.m_v[6];
			inv.m_v[6] = -m.m_v[0] * m.m_v[6] * m.m_v[15] + m.m_v[0] * m.m_v[7] * m.m_v[14] + m.m_v[4] * m.m_v[2] * m.m_v[15] - m.m_v[4] * m.m_v[3] * m.m_v[14] - m.m_v[12] * m.m_v[2] * m.m_v[7] + m.m_v[12] * m.m_v[3] * m.m_v[6];
			inv.m_v[10] = m.m_v[0] * m.m_v[5] * m.m_v[15] - m.m_v[0] * m.m_v[7] * m.m_v[13] - m.m_v[4] * m.m_v[1] * m.m_v[15] + m.m_v[4] * m.m_v[3] * m.m_v[13] + m.m_v[12] * m.m_v[1] * m.m_v[7] - m.m_v[12] * m.m_v[3] * m.m_v[5];
			inv.m_v[14] = -m.m_v[0] * m.m_v[5] * m.m_v[14] + m.m_v[0] * m.m_v[6] * m.m_v[13] + m.m_v[4] * m.m_v[1] * m.m_v[14] - m.m_v[4] * m.m_v[2] * m.m_v[13] - m.m_v[12] * m.m_v[1] * m.m_v[6] + m.m_v[12] * m.m_v[2] * m.m_v[5];
			inv.m_v[3] = -m.m_v[1] * m.m_v[6] * m.m_v[11] + m.m_v[1] * m.m_v[7] * m.m_v[10] + m.m_v[5] * m.m_v[2] * m.m_v[11] - m.m_v[5] * m.m_v[3] * m.m_v[10] - m.m_v[9] * m.m_v[2] * m.m_v[7] + m.m_v[9] * m.m_v[3] * m.m_v[6];
			inv.m_v[7] = m.m_v[0] * m.m_v[6] * m.m_v[11] - m.m_v[0] * m.m_v[7] * m.m_v[10] - m.m_v[4] * m.m_v[2] * m.m_v[11] + m.m_v[4] * m.m_v[3] * m.m_v[10] + m.m_v[8] * m.m_v[2] * m.m_v[7] - m.m_v[8] * m.m_v[3] * m.m_v[6];
			inv.m_v[11] = -m.m_v[0] * m.m_v[5] * m.m_v[11] + m.m_v[0] * m.m_v[7] * m.m_v[9] + m.m_v[4] * m.m_v[1] * m.m_v[11] - m.m_v[4] * m.m_v[3] * m.m_v[9] - m.m_v[8] * m.m_v[1] * m.m_v[7] + m.m_v[8] * m.m_v[3] * m.m_v[5];
			inv.m_v[15] = m.m_v[0] * m.m_v[5] * m.m_v[10] - m.m_v[0] * m.m_v[6] * m.m_v[9] - m.m_v[4] * m.m_v[1] * m.m_v[10] + m.m_v[4] * m.m_v[2] * m.m_v[9] + m.m_v[8] * m.m_v[1] * m.m_v[6] - m.m_v[8] * m.m_v[2] * m.m_v[5];

			T det = m.m_v[0] * inv.m_v[0] + m.m_v[1] * inv.m_v[4] + m.m_v[2] * inv.m_v[8] + m.m_v[3] * inv.m_v[12];

			if (det == static_cast<T>(0))
				return false;

			det = static_cast<T>(1) / det;

			for (ui8f i = 0; i < 16; i++)
			{
				result.m_v[i] = inv.m_v[i] * det;
			}

			return true;
		}

		Matrix4<T> operator*(const Matrix4<T> &m)
		{
			Matrix4<T> result;
			for (ui8f x = 0; x < 4; x++)
			{
				for (ui8f y = 0; y < 4; y++)
				{
					result.set(x, y, get(static_cast<ui8f>(0), y) * m.get(x, static_cast<ui8f>(0)) + get(static_cast<ui8f>(1), y) * m.get(x, static_cast<ui8f>(1)) + get(static_cast<ui8f>(2), y) * m.get(x, static_cast<ui8f>(2)) + get(static_cast<ui8f>(3), y) * m.get(x, static_cast<ui8f>(3)));
				}
			}
			return result;
		}

		template <typename T2>
		inline FL_CONSTEXPR T get(T2 x, T2 y) const { return m_v[x * 4 + y]; }
		template <typename T2>
		inline void set(T2 x, T2 y, T v) { m_v[x * 4 + y] = v; }

		template <typename T2>
		inline FL_CONSTEXPR operator Matrix4<T2>() const { return Matrix4<T2>(static_cast<T2>(m_v[0]), static_cast<T2>(m_v[4]), static_cast<T2>(m_v[8]), static_cast<T2>(m_v[12]), static_cast<T2>(m_v[1]), static_cast<T2>(m_v[5]), static_cast<T2>(m_v[9]), static_cast<T2>(m_v[13]), static_cast<T2>(m_v[2]), static_cast<T2>(m_v[6]), static_cast<T2>(m_v[10]), static_cast<T2>(m_v[14]), static_cast<T2>(m_v[3]), static_cast<T2>(m_v[7]), static_cast<T2>(m_v[11]), static_cast<T2>(m_v[15])); }

		inline const T *getData() const { return m_v; }
		inline T *getPointer() { return m_v; }

	private:
		T m_v[16];
	};

	template <typename T>
	FL_CONSTEXPR Vector4<T> operator*(const Matrix4<T> &a, const Vector4<T> &b)
	{
		return Vector4<T>(a.get(0, 0) * b.x + a.get(1, 0) * b.y + a.get(2, 0) * b.z + a.get(3, 0) * b.w, a.get(0, 1) * b.x + a.get(1, 1) * b.y + a.get(2, 1) * b.z + a.get(3, 1) * b.w, a.get(0, 2) * b.x + a.get(1, 2) * b.y + a.get(2, 2) * b.z + a.get(3, 2) * b.w, a.get(0, 3) * b.x + a.get(1, 3) * b.y + a.get(2, 3) * b.z + a.get(3, 3) * b.w);
	}

	template <typename T>
	void operator*=(Matrix4<T> &a, const Matrix4<T> &b)
	{
		Matrix4<T> m = a * b;
		memcpy(a.getPointer(), m.getData(), sizeof(m));
	}

}