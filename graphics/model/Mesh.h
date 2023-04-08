#pragma once

#include "GLModel.h"
#include "Attribute.h"
#include "../../util/Vector.h"

namespace fl
{

    template <typename Vertex>
    class Mesh
    {
    public:
        FL_CONSTEXPR Mesh() : m_vertices(), m_attributes() {}
        ~Mesh() {}

        inline void addAttribute(const Attribute &attribute) { m_attributes.pushBack(attribute); }

        void createGLModel(GLModel &model, UsageHint usageHint = USAGE_HINT_STATIC)
        {
            model.setData(m_vertices.data(), m_vertices.size(), m_attributes.data(), m_attributes.size(), usageHint);
        }

        inline void vertex(const Vertex &v) { m_vertices.push_back(v); }

        void triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2)
        {
            m_vertices.pushBack(v0);
            m_vertices.pushBack(v1);
            m_vertices.pushBack(v2);
        }

        void quad(const Vertex &v0, const Vertex &v1, const Vertex &v2, const Vertex &v3)
        {
            m_vertices.pushBack(v0);
            m_vertices.pushBack(v1);
            m_vertices.pushBack(v2);

            m_vertices.pushBack(v0);
            m_vertices.pushBack(v2);
            m_vertices.pushBack(v3);
        }

        void clear()
        {
            m_vertices = Vector<Vertex>();
        }

        void calculateNormals(ui32f positionOffset, ui32f normalOffset)
        {
            for (unsigned int i = 0; i < m_vertices.getSize(); i += 3)
            {
                f32v3 *p0 = reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 0]) + positionOffset);
                f32v3 *p1 = reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 1]) + positionOffset);
                f32v3 *p2 = reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 2]) + positionOffset);
                f32v3 normal = (*p1 - *p0).cross(*p2 - *p0).normalized();
                *reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 0]) + normalOffset) = normal;
                *reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 1]) + normalOffset) = normal;
                *reinterpret_cast<f32v3>(reinterpret_cast<ui8 *>(&m_vertices[i + 2]) + normalOffset) = normal;
            }
        }

        inline Vector<Vertex> &getVertices() { return m_vertices; }
        inline Vector<Attribute> &getAttributes() { return m_attributes; }
        inline bool isEmpty() const { return m_vertices.size() == 0; }
        inline void reserveVertices(ui32f count) { m_vertices.reserve(count); }
        inline void reserveAttributes(ui32f count) { m_attributes.reserve(count); }
        inline void shrinkVertices() { m_vertices.shrinkToFit(); }
        inline void shrinkAttributes() { m_attributes.shrinkToFit(); }

    private:
        Vector<Vertex> m_vertices;
        Vector<Attribute> m_attributes;
    };

}