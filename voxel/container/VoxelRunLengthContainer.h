#pragma once

#include "../../Build.h"
#include "VoxelContainer.h"
#include "../../util/Vector.h"

namespace fl
{
    template<typename VoxelData>
    class VoxelRunLengthData
    {
        public:
            VOxelData data;
            ui32f length;

            inline VoxelRunLengthData() {}
            inline VoxelRunLengthData(const VoxelData& data, ui32f length) : data(data), length(length) {}
		    inline ~VoxelRunLengthData() {}
    };


	template<typename VoxelData, ui32f width, ui32f height, ui32f length>
	class VoxelRunLengthContainer : public VoxelContainer
	{
	public:
		VoxelRunLengthContainer() {  }
		~VoxelRunLengthContainer() override {  }

		inline const VoxelData& getData(ui32f x, ui32f y, ui32f z) const override
		{
			ui32f index = getIndex(x, y, z);
			ui32f current = 0;
			
		}

		inline void setData(ui32f x, ui32f y, ui32f z, const VoxelData& data) override { m_data[x][y][z] = data; }

		inline void clear(const VoxelData& data) override { m_data = Vector<VoxelRunLengthData<VoxelData>>(); m_data.pushBack(VoxelRunLengthData(data, width * height * length)); }
	private:
		inline ui32f getIndex(ui32f x, ui32f y, ui32f z) const { return x + y * width + z * width * height; }

		Vector<VoxelRunLengthData<VoxelData>> m_data;
	};

}