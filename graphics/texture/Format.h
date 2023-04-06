#pragma once

#include "../../Types.h"

namespace fl 
{
    enum Format
    {
        FORMAT_R8,
		FORMAT_RG8,
		FORMAT_RGB8,
		FORMAT_RGBA8,
		FORMAT_R32F,
		FORMAT_RG32F,
		FORMAT_RGB32F,
		FORMAT_DEPTH16,
		FORMAT_DEPTH24,
		FORMAT_DEPTH32,
		FORMAT_SHADOW16_NEAREST,
		FORMAT_SHADOW24_NEAREST,
		FORMAT_SHADOW32_NEAREST,
		FORMAT_SHADOW16_LINEAR,
		FORMAT_SHADOW24_LINEAR,
		FORMAT_SHADOW32_LINEAR
    };

    namespace format
    {
        extern ui32 getGLFormat(Format format);
		extern ui32 getGLInternalFormat(Format format);
		extern ui32 getGLType(Format format);
		extern ui32 getGLAlignment(Format format);

    }
}