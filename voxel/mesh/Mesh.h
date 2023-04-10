#pragma once

#include "../../graphics/model/IndexedMesh.h"
#include "../../graphics/model/GLIndexedModel.h"

namespace fl
{
    template <typename Vertex, typename Index>
    class VoxelMesh
    {
    public:
        // EMPTY FOR NOW
    private:
        IndexedMesh<Vertex, Index> m_mesh;
        GLIndexedModel m_model;
    };
}