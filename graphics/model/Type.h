#pragma once

#include "../../Types.h"

namespace fl
{
    enum Type
    {
        FLOAT,
        DOUBLE,
        UNSIGNED_BYTE,
        UNSIGNED_SHORT,
        UNSIGNED_INT,
        UNKNOWN
    };

    namespace type
    {
        extern ui32 getGLType(const Type &type);
        extern ui32 getGLTypeSize(const Type &type);
    }
}