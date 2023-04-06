#pragma once

#include "Window.h"

struct SDL_Window;

namespace fl
{
    class FL_API SDLWindow : public Window
    {
    public:
        SDLWindow();
        ~SDLWindow();

        void initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VerticalSync &vsync) override;
        void cleanup() override;

        void update() override;
        void swap() override;

        void bind() const override;

        bool isCloseRequested() override;
        ui16f getWidth() const override;
        ui16f getHeight() const override;
        f32 getAspectRatio() const override;
        bool isMouseGrabbed() const override;

        void setMouseGrabbed(bool grabbed) const override;

        void captureScreenshot(cString file) const override;

    private:
        SDL_Window *m_window;
        void *m_context;
        bool m_closeRequested;

        std::unordered_map<int, int> m_keyMap;
        std::unordered_map<int, int> m_buttonMap;
    };
}