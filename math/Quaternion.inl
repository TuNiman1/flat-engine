#include "Matrix3.h"
#include "Matrix4.h"

namespace fl
{

	template <typename T>
	Quaternion<T>::Quaternion(const Matrix3<T> &m)
	{
		const T diagonal = m.get(0, 0) + m.get(1, 1) + m.get(2, 2);
		if (diagonal > 0)
		{
			const T r = sqrt(static_cast<T>(1) + diagonal);
			const T s = static_cast<T>(0.5) / r;
			w = static_cast<T>(0.5) * r;
			x = (m.get(1, 2) - m.get(2, 1)) * s;
			y = (m.get(2, 0) - m.get(0, 2)) * s;
			z = (m.get(0, 1) - m.get(1, 0)) * s;
		}
		else if ((m.get(0, 0) > m.get(1, 1)) && (m.get(0, 0) > m.get(1, 1)))
		{
			const T r = sqrt(static_cast<T>(1) + m.get(0, 0) - m.get(1, 1) - m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(1, 2) - m.get(2, 1)) * s;
			x = static_cast<T>(0.5) * r;
			y = (m.get(0, 1) + m.get(1, 0)) * s;
			z = (m.get(0, 2) + m.get(2, 0)) * s;
		}
		else if ((m.get(1, 1) > m.get(0, 0)) && (m.get(1, 1) > m.get(2, 2)))
		{
			const T r = sqrt(static_cast<T>(1) - m.get(0, 0) + m.get(1, 1) - m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(2, 0) - m.get(0, 2)) * s;
			x = (m.get(0, 1) + m.get(1, 0)) * s;
			y = static_cast<T>(0.5) * r;
			z = (m.get(1, 2) + m.get(2, 1)) * s;
		}
		else
		{
			const T r = sqrt(static_cast<T>(1) - m.get(0, 0) - m.get(1, 1) + m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(0, 1) - m.get(1, 0)) * s;
			x = (m.get(0, 2) + m.get(2, 0)) * s;
			y = (m.get(1, 2) + m.get(2, 1)) * s;
			z = static_cast<T>(0.5) * r;
		}
	}

	template <typename T>
	Quaternion<T>::Quaternion(const Matrix4<T> &m)
	{
		const T diagonal = m.get(0, 0) + m.get(1, 1) + m.get(2, 2);
		if (diagonal > 0)
		{
			const T r = sqrt(static_cast<T>(1) + diagonal);
			const T s = static_cast<T>(0.5) / r;
			w = static_cast<T>(0.5) * r;
			x = (m.get(1, 2) - m.get(2, 1)) * s;
			y = (m.get(2, 0) - m.get(0, 2)) * s;
			z = (m.get(0, 1) - m.get(1, 0)) * s;
		}
		else if ((m.get(0, 0) > m.get(1, 1)) && (m.get(0, 0) > m.get(1, 1)))
		{
			const T r = sqrt(static_cast<T>(1) + m.get(0, 0) - m.get(1, 1) - m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(1, 2) - m.get(2, 1)) * s;
			x = static_cast<T>(0.5) * r;
			y = (m.get(0, 1) + m.get(1, 0)) * s;
			z = (m.get(0, 2) + m.get(2, 0)) * s;
		}
		else if ((m.get(1, 1) > m.get(0, 0)) && (m.get(1, 1) > m.get(2, 2)))
		{
			const T r = sqrt(static_cast<T>(1) - m.get(0, 0) + m.get(1, 1) - m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(2, 0) - m.get(0, 2)) * s;
			x = (m.get(0, 1) + m.get(1, 0)) * s;
			y = static_cast<T>(0.5) * r;
			z = (m.get(1, 2) + m.get(2, 1)) * s;
		}
		else
		{
			const T r = sqrt(static_cast<T>(1) - m.get(0, 0) - m.get(1, 1) + m.get(2, 2));
			const T s = static_cast<T>(0.5) / r;
			w = (m.get(0, 1) - m.get(1, 0)) * s;
			x = (m.get(0, 2) + m.get(2, 0)) * s;
			y = (m.get(1, 2) + m.get(2, 1)) * s;
			z = static_cast<T>(0.5) * r;
		}
	}

}