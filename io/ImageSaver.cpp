#define STB_IMAGE_WRITE_IMP
#include "../stb/stb_image_write.h"
#include "ImageSaver.h"


namespace fl {
	namespace io {

		void savePNG(cString file, const ui8* data, ui32f width, ui32f height, const Format& format)
		{
			i32f comp;
			switch (format) {
			case FORMAT_R8: comp = 1; break;
			case FORMAT_RG8: comp = 2; break;
			case FORMAT_RGB8: comp = 3; break;
			case FORMAT_RGBA8: comp = 4; break;
			}
			stbi_write_png(file, width, height, comp, data, comp * width);
		}

		void saveBMP(cString file, const ui8* data, ui32f width, ui32f height, const Format& format)
		{
			i32f comp;
			switch (format) {
			case FORMAT_R8: comp = 1; break;
			case FORMAT_RG8: comp = 2; break;
			case FORMAT_RGB8: comp = 3; break;
			case FORMAT_RGBA8: comp = 4; break;
			}
			stbi_write_bmp(file, width, height, comp, data);
		}

        void saveJGP(cString file, const ui8* data, ui32f width, ui32f height, int quality, const Format& format)
        {
            i32f comp;
            switch (format) {
			case FORMAT_R8: comp = 1; break;
			case FORMAT_RG8: comp = 2; break;
			case FORMAT_RGB8: comp = 3; break;
			case FORMAT_RGBA8: comp = 4; break;   
            }
            stbi_write_jpg(file, width, height, comp, data, quality);
        }

	}
}
