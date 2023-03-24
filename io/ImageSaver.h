#pragma once

#include "../Build.h"
#include "../Types.h"

#include "../graphics/texture/Format.h"

namespace fl
{
    namespace io
    {
        extern FL_API void savePNG(cString file, const ui8* data, ui32 width, ui32 height, const Format& format);
        extern FL_API void saveBMP(cString file, const ui8* data, ui32 width, ui32 height, const Format& format);
        extern FL_API void saveJPG(cString file, const ui8* data, ui32 width, ui32 height, const Format& format);
        extern FL_API void saveJPEG(cString file, const ui8* data, int quality, ui32 width, ui32 height, const Format& format);
    }
}