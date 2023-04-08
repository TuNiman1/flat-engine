#pragma once

#include "../../Types.h"

namespace fl
{
    enum Primitive
    {
        // Every vertex is rendered seperately as a point.
        P_POINT,
        // The vertices are considered as paires, they are connected by a line.
        P_LINE,
        // Every vertex is connected to its successor by a line.
        P_LINE_STRIP,
        // Every vertex is connected to its successor by a line.
        // And the first and last vertex are also connected by a line.
        P_LINE_LOOP,
        // Three vertices create a triangle shape.
        P_TRIANGLE,
        // Every vertex is connected to the previous 2 vertices to make a triangle.
        P_TRIANGLE_STRIP,
        // Every vertex is connected to the previous and the first vertex to make a triangle.
        P_TRIANGLE_FAN
    };

    namespace primitive
    {
        extern ui32 getGLPrimitive(const Primitive &primitive);
    }
}