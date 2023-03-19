#pragma once

#include "../Build.h"

#define FL_GRAPHICS_OPENGL

#ifdef FL_GRAPHICS_OPENGL
#define FL_GRAPHICS_GLFW
#endif

namespace fl
{
    enum GraphicsAPI
    {
        GRAPHICS_GLFW,
        GRAPHICS_SDL
    };

    namespace graphics
    {
        extern FL_API void initialize(const GraphicsAPI &api);
        extern FL_API void cleanup();
        extern FL_API const GraphicsAPI &getAPI();
    }
}