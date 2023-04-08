#include "UsageHint.h"
#include "../../glad/include/glad/glad.h"

namespace fl
{
    namespace usagehint
    {
        FL_API i32 getGLUsageHint(UsageHint usagehint)
        {
            switch (usagehint)
            {
            case UH_STATIC:
                return GL_STATIC_DRAW;
                break;
            case UH_DYNAMIC:
                return GL_DYNAMIC_DRAW;
                break;
            case UH_STREAM:
                return GL_STREAM_DRAW;
                break;
            }
            return 0;
        }
    }
}