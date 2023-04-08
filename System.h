#pragma once

#include "Build.h"

namespace fl
{
    namespace system
    {
        extern FL_API bool isBigEndianInteger();
        extern FL_API bool isBigEndianFloat();

        inline bool isLittleEndianInteger() { return !isBigEndianInteger(); }
        inline bool isLittleEndianFloat() { return !isBigEndianFloat(); }
    }
}