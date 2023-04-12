#pragma once
#include "../chunk/Chunk.h"

namespace fl
{
    template <typename VoxelData, ui16f chunkSize>
    class VoxelWorld
    {
    public:
        inline VoxelWorld() {}
        virtual inline ~VoxelWorld() {}

        virtual inline void initialize() {}
        virtual inline void cleanup() {}

        virtual inline Chunk<VoxelData, chunkSize> *getChunk(i32f x, i32f y, i32f z) = 0;
    };
}