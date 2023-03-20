#include "Window.h"

#include "GLFWWindow.h"
#include "SDLWindow.h"

#include "../GraphicsAPI.h"

namespace fl
{
    Window *Window::create()
    {
        switch (graphics::getAPI())
        {
#ifdef FL_GRAPHICS_GLFW
        case GRAPHICS_GLFW:
            return new GLFWWindow();
            break;
#endif

#ifdef FL_GRAPHICS_SDL
        case GRAPHICS_SDL:
            return new SDL_Window();
            break;
#endif
        }
        return nullptr;
    }
}