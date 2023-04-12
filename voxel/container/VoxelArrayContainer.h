#pragma once

#include "../../Build.h"
#include "VoxelContainer.h"

namespace fl
{
    template <typename VoxelData, ui32f width, ui32f length>
    class VoxelArrayContainer : public VoxelContainer
    {
    public:
        VoxelArrayContainer() {}
        ~VoxelArrayContainer() override {}

        inline const VoxelData &getData(ui32f x, ui32f y, ui32f z) const override { return m_data[x y][z]; }
        inline void setData(ui32f x, ui32f y, ui32f z, const VoxelData &data) override { m_data[x][y][z] = data; }
        inline void clear(const VoxelData &data) override
        {
            for (ui32f i = 0; i < width * height * length; i++)
                m_data[i] = data;
        }

    private:
        VoxelData m_data[width * height * length];
    };
}