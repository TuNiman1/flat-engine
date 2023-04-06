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

    void SDLWindow::initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VerticalSync &vsync)
    {
        SDL_DisplayMode mode;
        SDL_GetCurrentDisplayMode(0, &mode);

        if (width == WINDOW_RES)
            width = mode.w;
        if (height == WINDOW_RES)
            height = mode.h;

        ui32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
        if (fullscreen)
            flags |= SDL_WINDOW_FULLSCREEN;
        if (resizable)
            flags |= SDL_WINDOW_RESIZABLE;

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        m_window = SDL_CreateWindow(title, mode.w / 2 - width / 2, mode.h / 2 - height / 2, width, height, flags);
    }
}
