#pragma once

#include "../memory/Heap.h"

namespace fl
{

    template <typename T>
    class Vector
    {
    public:
        inline Vector() : m_data(nullptr), m_size(0), m_capacity(1) { m_data = reinterpret_cast<T *>(heap::allocateZero(m_capacity * sizeof(T))); }
        Vector(const Vector<T> &vector) : m_data(nullptr), m_size(vector.m_size), m_capacity(vector.m_capacity)
        {
            m_data = reinterpret_cast<T *>(heap::allocateZero(m_capacity * sizeof(T)));
            for (size_t i = 0; i < m_size; i++)
            {
                m_data[i] = vector.m_data[i];
            }
        }
        inline ~Vector() { heap::deallocate(m_data); }

        inline void pushBack(const T &element)
        {
            if (m_size >= m_capacity)
            {
                allocate(m_capacity * 2);
            }
            m_data[m_size++] = element;
        }
        inline void popBack()
        {
            m_size--;
            FL_DEBUG_ASSERT_M(m_size >= 0, "Cannot pop off the back of an empty vector.");
        }

        inline T &getFirstElement()
        {
            return m_data[0];
            FL_DEBUG_ASSERT_M(m_size >= 0, "Cannot read an element of an empty vector.");
        }
        inline T &getLastElement()
        {
            return m_data[m_size - 1];
            FL_DEBUG_ASSERT_M(m_size >= 0, "Cannot read an element of an empty vector.");
        }

        inline T &operator[](size_t index)
        {
            return m_data[index];
            FL_DEBUG_ASSERT_M(index >= 0 && index < m_size, "Index is out of bounds.");
        }
        inline const T &operator[](size_t index) const
        {
            return m_data[index];
            FL_DEBUG_ASSERT_M(index >= 0 && index < m_size, "Index is out of bounds.");
        }

        inline void reserve(size_t size)
        {
            if (size > m_capacity)
            {
                allocate(size);
            }
        }
        inline void shrinkToFit() { allocate(m_size); }

        inline void clear() { m_size = 0; }

        inline const T *data() const { return m_data; }
        inline size_t size() const { return m_size; }
        inline size_t capacity() const { return m_capacity; }

    private:
        void allocate(size_t capacity)
        {
            m_data = reinterpret_cast<T *>(heap::reallocate(m_data, capacity * sizeof(T)));
            if (m_capacity < capacity)
                FL_ZERO_MEMORY(m_data + m_capacity, (capacity - m_capacity) * sizeof(T));
            m_capacity = capacity;
        }

        T *m_data;
        size_t m_size;
        size_t m_capacity;
    };

}