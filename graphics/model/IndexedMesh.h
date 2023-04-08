#pragma once

#include "GLIndexedModel.h"
#include "Attribute.h"
#include "../../io/Console.h"
#include "../../util/Vector.h"

namespace fl
{

    template <typename Vertex, typename Index>
    class IndexedMesh
    {
    public:
        FL_CONSTEXPR IndexedMesh() : m_vertices(), m_indices(), m_attributes() {}
        ~IndexedMesh() {}

        inline void addAttribute(const Attribute &attribute) { m_attributes.pushBack(attribute); }

        void createGLModel(GLIndexedModel &model, UsageHint usageHint = USAGE_HINT_STATIC)
        {
            Type indexType;
            switch (sizeof(Index))
            {
            case 1:
                indexType = TYPE_UNSIGNED_BYTE;
                break;
            case 2:
                indexType = TYPE_UNSIGNED_SHORT;
                break;
            case 4:
                indexType = TYPE_UNSIGNED_INT;
                break;
            default:
                log::error("Index type of size ", sizeof(Index), " not supported");
                break;
            }
            model.setData(m_vertices.data(), m_vertices.size(), m_indices.data(), m_indices.size(), indexType, m_attributes.data(), m_attributes.size(), usageHint);
        }

        void vertex(const Vertex &v)
        {
            m_indices.pushBack(static_cast<Index>(m_vertices.size()));
            m_vertices.pushBack(v);
        }

        void triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2)
        {
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 1));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));

            m_vertices.pushBack(v0);
            m_vertices.pushBack(v1);
            m_vertices.pushBack(v2);
        }

        void quad(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Vertex &v3)
        {
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 1));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));
            m_indices.pushBack(static_cast<Index>(m_vertices.size() + 3));

            m_vertices.pushBack(v0);
            m_vertices.pushBack(v1);
            m_vertices.pushBack(v2);
            m_vertices.pushBack(v3);
        }

        void clear()
        {
            m_vertices = Vector<Vertex>();
            m_indices = Vector<Index>();
        }

        inline Vector<Vertex> &getVertices() { return m_vertices; }
        inline Vector<Index> &getIndices() { return m_indices; }
        inline Vector<Attribute> &getAttributes() { return m_attributes; }
        inline bool isEmpty() const { return m_indices.size() == 0; }

        inline void reserveVertices(ui32f count) { m_vertices.reserve(count); }
        inline void reserveIndices(ui32f count) { m_indices.reserve(count); }
        inline void reserveAttributes(ui32f count) { m_attributes.reserve(count); }

        inline void shrinkVertices() { m_vertices.shrinkToFit(); }
        inline void shrinkIndices() { m_indices.shrinkToFit(); }
        inline void shrinkAttributes() { m_attributes.shrinkToFit(); }

    private:
        Vector<Vertex> m_vertices;
        Vector<Index> m_indices;
        Vector<Attribute> m_attributes;
    };

}