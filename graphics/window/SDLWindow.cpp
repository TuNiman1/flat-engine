#include "SDLWindow.h"

#include "../GraphicsAPI.h"

#ifdef FL_GRAPHICS_SDL

#include "../../glad/include/glad/glad.h"
#include <SDL2/SDL.h>

#include "../../debug/Exception.h"

namespace fl
{
    SDLWindow::SDLWindow() : Window(INPUTCODES_SDL), m_window(nullptr), m_context(), m_closeRequested(false)
    {
    }

    SDLWindow::~SDLWindow()
    {
    }
}
#endif