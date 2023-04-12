#pragma once

#include "../../Types.h"
#include "../container/VoxelArrayContainer.h"
#include "../mesh/Mesh.h"

namespace fl
{
    template <typename VoxelData, ui16f size, typename Vertex>
    class Chunk
    {
    public:
        Chunk() : m_position(), m_container(nullptr) {}
        ~Chunk() {}

        void initialize(const i32v3 &position)
        {
            m_position = position;
            m_container = new VoxelArrayContainer<VoxelData, size, size, size>()
        }

        void cleanup()
        {
            delete m_container;
        }

        inline const i32v3 &getPosition() const { return m_positon; }

    private:
        static inline VT_CONSTEXPR requires32BitIndices(ui16f size) { return (size / 2) * (size / 2) * (size / 2) * (6 * 4) > 65535; }

        i32v3 m_position;
        VoxelContainer<VoxelData, size, size, size> *m_container;
        VoxelMesh<Vertex, requires32BitIndices(size) ? ui32 : ui16> m_mesh;
    };
}