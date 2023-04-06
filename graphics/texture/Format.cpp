#include "Format.h"

#include "../../glad/include/glad/glad.h"
#include "../../io/Console.h"

namespace fl {
	namespace format {

		ui32 getGLFormat(Format format)
		{
			switch (format) {
			case FORMAT_R8: return GL_RED; break;
			case FORMAT_RG8: return GL_RG; break;
			case FORMAT_RGB8: return GL_RGB; break;
			case FORMAT_RGBA8: return GL_RGBA; break;
			case FORMAT_R32F: return GL_RED; break;
			case FORMAT_RG32F: return GL_RG; break;
			case FORMAT_RGB32F: return GL_RGB; break;
			case FORMAT_DEPTH16: return GL_DEPTH_COMPONENT; break;
			case FORMAT_DEPTH24: return GL_DEPTH_COMPONENT; break;
			case FORMAT_DEPTH32: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW16_NEAREST: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW24_NEAREST: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW32_NEAREST: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW16_LINEAR: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW24_LINEAR: return GL_DEPTH_COMPONENT; break;
			case FORMAT_SHADOW32_LINEAR: return GL_DEPTH_COMPONENT; break;
			default: log::error("Invalid format: ", format); break;
			}
			return 0;
		}

		ui32 getGLInternalFormat(Format format)
		{
			switch (format) {
			case FORMAT_R8: return GL_R8; break;
			case FORMAT_RG8: return GL_RG8; break;
			case FORMAT_RGB8: return GL_RGB8; break;
			case FORMAT_RGBA8: return GL_RGBA8; break;
			case FORMAT_R32F: return GL_R32F; break;
			case FORMAT_RG32F: return GL_RG32F; break;
			case FORMAT_RGB32F: return GL_RGB32F; break;
			case FORMAT_DEPTH16: return GL_DEPTH_COMPONENT16; break;
			case FORMAT_DEPTH24: return GL_DEPTH_COMPONENT24; break;
			case FORMAT_DEPTH32: return GL_DEPTH_COMPONENT32; break;
			case FORMAT_SHADOW16_NEAREST: return GL_DEPTH_COMPONENT16; break;
			case FORMAT_SHADOW24_NEAREST: return GL_DEPTH_COMPONENT24; break;
			case FORMAT_SHADOW32_NEAREST: return GL_DEPTH_COMPONENT32; break;
			case FORMAT_SHADOW16_LINEAR: return GL_DEPTH_COMPONENT16; break;
			case FORMAT_SHADOW24_LINEAR: return GL_DEPTH_COMPONENT24; break;
			case FORMAT_SHADOW32_LINEAR: return GL_DEPTH_COMPONENT32; break;
			default: log::error("Invalid format: ", format); break;
			}
			return 0;
		}

		ui32 getGLType(Format format)
		{
			switch (format) {
			case FORMAT_R8: return GL_UNSIGNED_BYTE; break;
			case FORMAT_RG8: return GL_UNSIGNED_BYTE; break;
			case FORMAT_RGB8: return GL_UNSIGNED_BYTE; break;
			case FORMAT_RGBA8: return GL_UNSIGNED_BYTE; break;
			case FORMAT_R32F: return GL_FLOAT; break;
			case FORMAT_RG32F: return GL_FLOAT; break;
			case FORMAT_RGB32F: return GL_FLOAT; break;
			case FORMAT_DEPTH16: return GL_FLOAT; break;
			case FORMAT_DEPTH24: return GL_FLOAT; break;
			case FORMAT_DEPTH32: return GL_FLOAT; break;
			case FORMAT_SHADOW16_NEAREST: return GL_FLOAT; break;
			case FORMAT_SHADOW24_NEAREST: return GL_FLOAT; break;
			case FORMAT_SHADOW32_NEAREST: return GL_FLOAT; break;
			case FORMAT_SHADOW16_LINEAR: return GL_FLOAT; break;
			case FORMAT_SHADOW24_LINEAR: return GL_FLOAT; break;
			case FORMAT_SHADOW32_LINEAR: return GL_FLOAT; break;
			default: log::error("Invalid format: ", format); break;
			}
			return 0;
		}

		ui32 getGLAlignment(Format format)
		{
			switch (format) {
			case FORMAT_R8: return 1; break;
			case FORMAT_RG8: return 2; break;
			case FORMAT_RGB8: return 4; break;
			case FORMAT_RGBA8: return 4; break;
			case FORMAT_R32F: return 4; break;
			case FORMAT_RG32F: return 8; break;
			case FORMAT_RGB32F: return 4; break;
			case FORMAT_DEPTH16: return 2; break;
			case FORMAT_DEPTH24: return 1; break;
			case FORMAT_DEPTH32: return 4; break;
			case FORMAT_SHADOW16_NEAREST: return 2; break;
			case FORMAT_SHADOW24_NEAREST: return 1; break;
			case FORMAT_SHADOW32_NEAREST: return 4; break;
			case FORMAT_SHADOW16_LINEAR: return 2; break;
			case FORMAT_SHADOW24_LINEAR: return 1; break;
			case FORMAT_SHADOW32_LINEAR: return 4; break;
			default: log::error("Invalid format: ", format); break;
			}
			return 0;
		}

	}
}