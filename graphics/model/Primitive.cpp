#include "Primitive.h"
#include "../../glad/include/glad/glad.h"
#include "../../io/Console.h"

namespace fl
{
    namespace primitive
    {
        ui32 getGLPrimitive(const Primitive &primitive)
        {
            switch (primitive)
            {
            case P_POINT:
                return GL_POINTS;
                break;
            case P_LINE:
                return GL_LINES;
                break;
            case P_LINE_STRIP:
                return GL_LINE_STRIP;
                break;
            case P_LINE_LOOP:
                return GL_LINE_LOOP;
                break;
            case P_TRIANGLE:
                return GL_TRIANGLES;
                break;
            case P_TRIANGLE_FAN:
                return GL_TRIANGLE_FAN;
                break;
            default:
                log::error("Invalid Primitive: ", primitive);
                break;
            }
            return 0;
        }
    }
}