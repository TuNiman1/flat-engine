#pragma once

#include "../../Build.h"
#include "../../Types.h"

#include "UsageHint.h"

namespace fl
{
    class Attribute;
    enum Type;
    enum Primitive;

    class FL_API GLIndexedModel
    {
    public:
        GLIndexedModel();
        ~GLIndexedModel();

        void initialize();
        void cleanup();

        void setData(const void *vertexData, ui32 numVertices, const void *indexData, ui32 numIndices, const Type &indexType, const Attribute *attributes, ui32 numAttributes, UsageHint usageHint = UH_STATIC);
        void render() const;

        void setPrimitive(const Primitive &primitive);

        inline bool isInitialized() const { return m_vbo != 0; }

    private:
        ui32 m_vbo;
        ui32 m_ibo;
        ui32 m_vao;
        ui32 m_primitive;
        ui32 m_indexType;
        ui32 m_numIndices;
    };
}