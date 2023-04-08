#include "ALSrc.h"

#include <AL/al.h>
#include "ALBuff.h"

namespace fl
{
    ALSrc::ALSrc() : m_source(0)
    {
    }

    ALSrc::~ALSrc()
    {
    }

    void ALSrc::initialize()
    {
        alGenSources(1, &m_source);
        alSourcef(m_source, AL_GAIN, 1.0f);
        alSourcef(m_source, AL_PITCH, 1.0f);
    }

    void ALSrc::cleanup()
    {
        stop();
        alDeleteBuffers(1, &m_source);
    }

    void ALSrc::play(const ALBuff &buffer)
    {
        alSourcei(m_source, AL_BUFFER, buffer.m_buffer);
        alSourcePlay(m_source);
    }

    void ALSrc::stop()
    {
        alSourceStop(m_source);
    }

    void ALSrc::setLooping(bool isLooping)
    {
        alSourcei(m_source, AL_LOOPING, isLooping ? AL_TRUE : AL_FALSE);
    }

    void ALSrc::setPos(const f32v3 &position)
    {
        alSource3f(m_source, AL_POSITION, position.x, position.y, position.z);
    }

    void ALSrc::setVel(const f32v3 &velocity)
    {
        alSource3f(m_source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
    }
}