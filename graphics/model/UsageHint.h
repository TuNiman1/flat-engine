#pragma once

#include "../../Build.h"
#include "../../Primitives.h"

namespace fl
{
    enum UsageHint
    {
        UH_STATIC,
        UH_DYNAMIC,
        UH_STREAM
    };

    namespace usagehint
    {
        extern FL_API i32 getGLUsageHint(UsageHint usagehint);
    }
}