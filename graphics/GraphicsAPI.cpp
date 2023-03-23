#include "GraphicsAPI.h"
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include "../debug/Exception.h"

#ifdef FL_VISUAL_C_PLUS_PLUS
#ifdef FL_GRAPHICS_OPENGL
#pragma comment(lib, "opengl32.lib")
#endif

#ifdef FL_GRAPHICS_SDL
#ifdef FL_ENVIRONMENT_32
#pragma comment(lib, "x86/SDL/SDL2.lib")
#pragma comment(lib, "x86/SDL/SDL2main.lib")
#else
#pragma comment(lib, "x64/SDL/SDL2.lib")
#pragma comment(lib, "x64/SDL/SDL2main.lib")
#endif
#endif
#endif

namespace fl
{
    namespace graphics
    {
        // The Graphics API is graphics_api.

        GraphicsAPI graphics_api;

        void initialize(const GraphicsAPI graphics_api)
        {
            switch (graphics_api)
            {
#ifdef FL_GRAPHICS_GLFW
            case GRAPHICS_GLFW:
                if (!glfwInit())
                {
                    log::fatal("Failed to initialize GLFW.");
                    exception::crash();
                }
                break;
#endif
#ifdef FL_GRAPHICS_SDL
            case GRAPHICS_SDL:
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    log::fatal("Failed to initialize SDL");
                    exception::crash();
                }
                break;
#endif
            default:
                log::fatal("Invalid Graphics API: ", graphics_api);
                exception::crash();
            }
            graphics::graphics_api = graphics_api;
        }

        void cleanup() 
        {
            switch (graphics_api)
            {
#ifdef FL_GRAPHICS_GLFW
            case GRAPHICS_GLFW:
                glfwTerminate();
                break;
#endif
#ifdef FL_GRAPHICS_SDL
            case GRAPHICS_SDL:
                SDL_Quit();
                break();
#endif
            default:
                log::fatal("Invalid graphics API: ", graphics_api);
                exception::crash();
            }
        }

        const GraphicsAPI &getAPI()
        {
            return graphics_api;
        }
    }
}