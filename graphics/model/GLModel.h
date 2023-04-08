#pragma once

#include "../../Build.h"
#include "../../Types.h"

#include "UsageHint.h"

namespace fl
{
    class Attribute;
    enum Type;
    enum Primitive;

    class FL_API GLModel
    {
    public:
        GLModel();
        ~GLModel();

        void initialize();
        void cleanup();

        void setData(const void *vertexData, ui32 numVertices, const Attribute *attributes, ui32 numAttributes, UsageHint usagehint = UH_STATIC);

        inline void render() const { render(m_numVertices); }
        void render(ui32 numVertices) const;

        void *map();
        void unmap();

        void setPrimitive(const Primitive &primitive);

        inline bool isInitialized() const { return m_vbo != 0; }
        inline ui32f getNumVertices() const { return m_numVertices; }

    private:
        ui32 m_vbo;
        ui32 m_vao;
        ui32 m_primitive;
        ui32 m_numVertices;

        void *m_mappedPointer;
    };
}