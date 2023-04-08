#pragma once

#include "../Build.h"
#include "../util/Camera.h"
#include "Types.h"

namespace fl
{
    class FL_API ALListener
    {
    public:
        ALListener();
        ~ALListener();

        void setPos(const f32v3 &position);
        void setVel(const f32v3 &velocity);
        void setOrientation(const f32v3 &direction, const f32v3 &up);

        void applyCam(const Camera<f32> &camera);
    };
}