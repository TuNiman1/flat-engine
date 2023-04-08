#pragma once

#include "../Build.h"

#include "ALSrc.h"

namespace fl
{
    class FL_API ALBuff
    {
        friend class ALSrc;

    public:
        ALBuff();
        ~ALBuff();

        void initialize();
        void cleanup();

        void setData(ui16f numChannels, ui16f bitsPerSample, const void *data, i32 size, i32 frequency);
        void loadWAV(cString file);
        void loadOGG(cString file);
        void loadMP3(cString file);

    private:
        ui32 m_buffer;
    };
}