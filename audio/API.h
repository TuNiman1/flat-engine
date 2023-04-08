#pragma once

#include "../Build.h"

#define FL_AUDIO_OPENAL

namespace fl
{
    enum AudioAPI
    {
        AUDIO_OPENAL
    };

    namespace audio
    {
        extern FL_API void initialize(const AudioAPI &api);
        extern FL_API void cleanup();
        extern FL_API const AudioAPI &getAPI();
    }
}