#pragma once

#include <string>

#include "../Build.h"
#include "../Primitives.h"
#include "Vector.h"

namespace fl
{
    typedef std::string String;

    extern FL_API Vector<String> splitString(const String &string, const String &sequence);

    template <typename T>
    static inline String toString(T v)
    {
        return std::to_string(v);
    }
}