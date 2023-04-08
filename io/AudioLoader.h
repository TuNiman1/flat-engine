#pragma once

#include "../Build.h"
#include "../Types.h"

namespace fl
{
    namespace io
    {
        // I'll add OGG and MP3 sometime in the future.
        extern FL_API void loadWAV(cString file, ui16f *numChannels, ui16f *bitsPerSample, ui8 **data, i32 *size, i32 *frequency);
    }
}