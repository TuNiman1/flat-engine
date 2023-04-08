#pragma once

#include "../Build.h"
#include "../Primitives.h"

namespace fl
{
    class Entity
    {
    public:
        Entity();
        ~Entity();

    private:
        ui32f m_id;
    };
}