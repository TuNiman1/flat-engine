#pragma once

#include "../Build.h"
#include "../Types.h"

namespace fl
{
    class ALBuff;

    class FL_API ALSrc
    {
    public:
        ALSrc();
        ~ALSrc();

        void initialize();
        void cleanup();

        void play(const ALBuff &buffer);
        void stop();

        void setLooping(bool looping);

        void setPos(const f32v3 &position);
        void setVel(const f32v3 &velocity);

    private:
        ui32 m_source;
    };
}