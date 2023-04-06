#include "SDLWindow.h"

#include "../GraphicsAPI.h"

// #ifdef FL_GRAPHICS_SDL

#include "../../glad/include/glad/glad.h"
#include <SDL2/SDL.h>

#include "../../debug/Exception.h"

namespace fl
{
    SDLWindow::SDLWindow() : Window(INPUT_SDL), m_window(nullptr), m_context(), m_closeRequested(false)
    {
    }

    SDLWindow::~SDLWindow()
    {
    }

    void SDLWindow::initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VSync &vsync)
    {
        SDL_DisplayMode mode;
        SDL_GetCurrentDisplayMode(0, &mode);

        if (width == WINDOW_MONITOR_RESOLUTION)
            width = mode.w;
    }
}
