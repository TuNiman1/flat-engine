#include "ALBuff.h"
#include <AL/al.h>

#include "../io/AudioLoader.h"

namespace fl
{
    ALBuff::ALBuff() : m_buffer(0)
    {
    }

    ALBuff::~ALBuff()
    {
    }

    void ALBuff::initialize()
    {
        alGenBuffers(1, &m_buffer);
    }

    void ALBuff::cleanup()
    {
        alDeleteBuffers(1, &m_buffer);
    }

    void ALBuff::setData(ui16f numChannels, ui16f bitsPerSample, const void *data, i32 size, i32 frequency)
    {
        i32 format = 0;
        if (numChannels == 1)
        {
            if (bitsPerSample == 8)
            {
                format = AL_FORMAT_MONO8;
            }
            else if (bitsPerSample == 16)
            {
                format = AL_FORMAT_MONO16;
            }
        }
        else if (numChannels == 2)
        {
            if (bitsPerSample == 8)
            {
                format = AL_FORMAT_STEREO8;
            }
            else if (bitsPerSample == 16)
            {
                format = AL_FORMAT_STEREO16;
            }
        }

        alBufferData(m_buffer, format, data, size, frequency);
    }

    void ALBuff::loadWAV(cString file)
    {
        ui16f numChannels;
        ui16f bitsPerSample;
        ui8 *data;
        i32 size;
        i32 frequency;

        io::loadWAV(file, &numChannels, &bitsPerSample, &data, &size, &frequency);

        setData(numChannels, bitsPerSample, data, size, frequency);

        delete[] data;
    }
}