#pragma once

#include "../Primitives.h"

namespace fl
{

	template <size_t numBytes, bool isUnsigned = false>
	class FixedWidthBigInteger
	{
	public:
		FixedWidthBigInteger() { FL_ZERO_MEMORY(m_data, sizeof(m_data)); }
		FixedWidthBigInteger(size_t value)
		{
			FL_ZERO_MEMORY(m_data, sizeof(m_data));
			FL_COPY_MEMORY(&value, m_data, sizeof(m_data) < sizeof(value) ? sizeof(m_data) : sizeof(value));
		}
		~FixedWidthBigInteger() {}

		inline operator FixedWidthBigInteger<numBytes, !isUnsigned>() const
		{
			FixedWidthBigInteger<numBytes, !isUnsigned> result;
			FL_COPY_MEMORY(m_data, result.m_data, sizeof(m_data));
			return result;
		}
		FixedWidthBigInteger<numBytes, isUnsigned> operator~() const
		{
			FixedWidthBigInteger<numBytes, !isUnsigned> result;
			for (size_t i = 0; i < numBytes; i++)
			{
				result.m_data[i] = ~m_data[i];
			}
			return result;
		}

		inline operator i8() const { return m_data[0]; }
		inline operator i16() const { return (static_cast<i16>(m_data[1]) << 8) | static_cast<i16>(m_data[0]); }
		inline operator i32() const { return (static_cast<i32>(m_data[3]) << 24) | (static_cast<i32>(m_data[2]) << 16) | (static_cast<i32>(m_data[1]) << 8) | static_cast<i32>(m_data[0]); }
		inline operator i64() const { return (static_cast<i64>(m_data[7]) << 56) | (static_cast<i64>(m_data[6]) << 48) | (static_cast<i64>(m_data[5]) << 40) | (static_cast<i64>(m_data[4]) << 32) | (static_cast<i64>(m_data[3]) << 24) | (static_cast<i64>(m_data[2]) << 16) | (static_cast<i64>(m_data[1]) << 8) | static_cast<i64>(m_data[0]); }

		inline const ui8 *getData() const { return m_data; }
		inline ui8 *getPointer() { return m_data; }

	private:
		ui8 m_data[numBytes];
	};

	template <size_t numBytes, bool isUnsigned>
	FixedWidthBigInteger<numBytes, isUnsigned> operator&(const FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		FixedWidthBigInteger<numBytes, isUnsigned> result;
		for (size_t i = 0; i < numBytes; i++)
		{
			result.getPointer()[i] = a.getData()[i] & b.getData()[i];
		}
		return result;
	}

	template <size_t numBytes, bool isUnsigned>
	FixedWidthBigInteger<numBytes, isUnsigned> operator|(const FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		FixedWidthBigInteger<numBytes, isUnsigned> result;
		for (size_t i = 0; i < numBytes; i++)
		{
			result.getPointer()[i] = a.getData()[i] | b.getData()[i];
		}
		return result;
	}

	template <size_t numBytes, bool isUnsigned>
	FixedWidthBigInteger<numBytes, isUnsigned> operator^(const FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		FixedWidthBigInteger<numBytes, isUnsigned> result;
		for (size_t i = 0; i < numBytes; i++)
		{
			result.getPointer()[i] = a.getData()[i] ^ b.getData()[i];
		}
		return result;
	}

	template <size_t numBytes, bool isUnsigned>
	bool operator>(const FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		for (size_t i = numBytes - 1; i >= 0; i--)
		{
			if (a.getData()[i] > b.getData()[i])
				return true;
			if (a.getData()[i] < b.getData()[i])
				return false;
		}
		return false;
	}

	template <size_t numBytes, bool isUnsigned>
	bool operator>=(const FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		for (size_t i = numBytes - 1; i >= 0; i--)
		{
			if (a.getData()[i] > b.getData()[i])
				return true;
			if (a.getData()[i] < b.getData()[i])
				return false;
		}
		return true;
	}

	template <size_t numBytes, bool isUnsigned>
	void operator+=(FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		size_t carry = 0;
		for (size_t i = 0; i < numBytes; i++)
		{
			size_t r = static_cast<size_t>(a.getData()[i]) + static_cast<size_t>(b.getData()[i]) + carry;
			a.getPointer()[i] = static_cast<ui8>(r);
			carry = r >> 8;
		}
	}

	template <size_t numBytes, bool isUnsigned>
	inline void operator-=(FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		size_t carry = 0;
		for (size_t i = 0; i < numBytes; i++)
		{
			size_t r = static_cast<size_t>(a.getData()[i]) + static_cast<size_t>(~b.getData()[i]) + 1 + carry;
			a.getPointer()[i] = static_cast<ui8>(r);
			carry = r >> 8;
		}
	}

	template <size_t numBytes, bool isUnsigned>
	inline void operator--(FixedWidthBigInteger<numBytes, isUnsigned> &a)
	{
		size_t carry = 0;
		for (size_t i = 0; i < numBytes; i++)
		{
			size_t r = static_cast<size_t>(a.getData()[i]) + ~1 + carry;
			a.getPointer()[i] = static_cast<ui8>(r);
			carry = r >> 8;
		}
	}

	template <size_t numBytes, bool isUnsigned>
	void operator*=(FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		FixedWidthBigInteger<numBytes, isUnsigned> aStart = a;
		while (b > FixedWidthBigInteger<numBytes, isUnsigned>(1))
		{
			a += aStart;
			b--;
		}
	}

	template <size_t numBytes, bool isUnsigned>
	void operator/=(FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		FixedWidthBigInteger<numBytes, isUnsigned> counter;
		while (a >= b)
		{
			a -= b;
			counter += 1;
		}
		a = counter;
	}

	template <size_t numBytes, bool isUnsigned>
	void operator%=(FixedWidthBigInteger<numBytes, isUnsigned> &a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		while (a >= b)
		{
			a -= b;
		}
	}

	template <size_t numBytes, bool isUnsigned>
	FixedWidthBigInteger<numBytes, isUnsigned> operator+(FixedWidthBigInteger<numBytes, isUnsigned> a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		a += b;
		return a;
	}

	template <size_t numBytes, bool isUnsigned>
	inline FixedWidthBigInteger<numBytes, isUnsigned> operator-(FixedWidthBigInteger<numBytes, isUnsigned> a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		a -= b;
		return a;
	}

	template <size_t numBytes, bool isUnsigned>
	FixedWidthBigInteger<numBytes, isUnsigned> operator*(FixedWidthBigInteger<numBytes, isUnsigned> a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		a *= b;
		return a;
	}

	template <size_t numBytes, bool isUnsigned>
	inline FixedWidthBigInteger<numBytes, isUnsigned> operator/(FixedWidthBigInteger<numBytes, isUnsigned> a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		a /= b;
		return a;
	}

	template <size_t numBytes, bool isUnsigned>
	inline FixedWidthBigInteger<numBytes, isUnsigned> operator%(FixedWidthBigInteger<numBytes, isUnsigned> a, const FixedWidthBigInteger<numBytes, isUnsigned> &b)
	{
		a %= b;
		return a;
	}

}