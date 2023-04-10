#pragma once

#include "../../../Types.h"

namespace fl
{
    class VoxelVertex
    {
        public:
            f32v3 position;
            VoxelVertex() {}
            VoxelVertex(const f32v3& position) : position(position) {}
            ~VoxelVertex() {} 
    }; 
}