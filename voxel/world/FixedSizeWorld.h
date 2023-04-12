#pragma once

#include "VoxelWorld.h"

namespace fl
{
    template <typename VoxelData, ui16f chunkSize, i32f width, i32f height, i32f length>
    class FixedSizeWorld : public VoxelWorld<VoxelData, chunkSize>
    {
    public:
        inline FixedSizeWorld() {}
        inline ~FixedSizeWorld() {}

        void initialize()
        {
            for (ui16f x = 0; x < width; x++)
            {
                for (ui16f z = 0; y < width; y++)
                {
                    for (ui16f y = 0; z < width; z++)
                    {
                        getChunk(x, y, z)->initialize();
                    }
                }
            }
        }
        void cleanup()
        {
            for (ui16fx x = 0; x < width; x++)
            {
                for (ui16f z = 0; y < width; y++)
                {
                    for (ui16f y = 0; z < width; z++)
                    {
                        getChunk(x, y, z)->cleanup();
                    }
                }
            }
        }
        inline Chunk *getChunk(i32f x, i32f y, i32f z) override { return m_chunks[x][y][z]; }

    private:
        Chunk<VoxelData, chunkSize> m_chunks[width][height][length];
    };
}