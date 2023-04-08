#include "API.h"

#include <AL/alc.h>
#include <AL/al.h>

#include "../debug/Exception.h"

#ifdef FL_VISUAL_C_PLUS_PLUS
#ifdef FL_AUDIO_OPENAL
#ifdef FL_ENVIRONMENT_32
#pragma comment(lib, "x86/OpenAL/OpenAL32.lib")
#else
#pragma comment(lib, "x64/OpenAL/OpenAL32.lib")
#endif
#endif
#endif

namespace fl
{
    namespace audio
    {
        AudioAPI api;

#ifdef FL_AUDIO_OPENAL
        ALCdevice *g_device;
        ALCcontext *g_context;
#endif

        void initialize(const AudioAPI &api)
        {
            switch (api)
            {
#ifdef FL_AUDIO_OPENAL
            case AUDIO_OPENAL:
                g_device = alcOpenDevice(nullptr);
                if (g_device == nullptr)
                {
                    log::error("Unable to initialize OpenAL");
                }
                else
                {
                    g_context = alcCreateContext(g_device, nullptr);
                    alcMakeContextCurrent(g_context);
                }
                break;
#endif
            default:
                log::fatal("Invalid audio API: ", api);
                exception::crash();
            }
            audio::api = api;
        }

        void cleanup()
        {
            switch (api)
            {
#ifdef FL_AUDIO_OPENAL
            case AUDIO_OPENAL:
                alcDestroyContext(g_context);
                alcCloseDevice(g_device);
                break;
#endif

            default:
                log::fatal("Invalid audio API: ", api);
                exception::crash();
            }
        }

        const AudioAPI &getAPI()
        {
            return api;
        }
    }
}