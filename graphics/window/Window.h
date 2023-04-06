#pragma once

#include "../../Build.h"
#include "Input.h"

namespace fl
{

    enum VerticalSync
    {
        VSYNC_DISABLED = 0,
        VSYNC_ENABLED = 1,
        VSYNC_HALF = 2
    };

    static const unsigned int WINDOW_RES = 0;

    class FL_API Window
    {
    protected:
        Window(const InputCodes &input_codes) : m_input(this, input_codes) {}
        virtual ~Window() {}

    public:
        virtual void initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VerticalSync &vsync) = 0;
        virtual void cleanup() = 0;

        virtual void update() = 0;
        virtual void swap() = 0;
        virtual void bind() const = 0;

        virtual bool isCloseRequested() = 0;
        virtual ui16f getWidth() const = 0;
        virtual ui16f getHeight() const = 0;
        virtual f32 getAspectRatio() const = 0;
        virtual bool isMouseGrabbed() const = 0;

        virtual void setMouseGrabbed(bool grabbed) const = 0;

        inline const Input &getInput() const { return m_input; }

        virtual void captureScreenshot(cString file) const = 0;

        static Window *create();
        static inline void destroy(Window *window)
        {
            delete window;
        }

    protected:
        Input m_input;
    };

}