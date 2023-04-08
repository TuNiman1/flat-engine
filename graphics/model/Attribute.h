#pragma once

#include "Type.h"
#include "../../Build.h"

namespace fl
{
    class FL_API Attribute
    {
    public:
        Type type;
        ui32 amount;
        bool normalized;

        FL_CONSTEXPR Attribute(const Type &type = UNKNOWN, ui32 amount = 0, bool normalized = false) : type(type), amount(amount), normalized(normalized) {}
        ~Attribute() {}
    };
}