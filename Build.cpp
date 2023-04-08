#include "Build.h"

#include "Flat.h"
#include "debug/Exception.h"
#include "graphics/GraphicsAPI.h"
#include "memory/Heap.h"

#ifdef FL_GRAPHICS_SDL
#include <SDL2/SDL_main.h>
int SDL_main(int argc, char **argv)
{
    fl::initialize();
    flmain();
    fl::cleanup();
    return 0;
}
#else
int main(int argc, char **argv)
{
    fl::initialize();
    flmain();
    fl::cleanup();
}
#endif

namespace fl
{
    void runtimeAssert(bool condition)
    {
        if (!condition)
        {
            fl::log::fatal("Assertion failed");
            fl::exception::crash();
        }
    }

    void runtimeAssert(bool condition, const char *message)
    {
        if (!condition)
        {
            fl::log::fatal("Assertation failed: ", message);
            fl::exception::crash();
        }
    }
}