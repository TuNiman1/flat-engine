#pragma once

#include <Window.h>

struct GLFWWindow;

namespace fl
{
    class FL_API GLFWWindow : public Window
    {
    public:
        GLFWWindow();
        ~GLFWWindow();

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

    protected:
        static void keyCallback(GLFWWindow *window, int key, int scancode, int action, int mods);
        static void buttonCallback(GLFWWindow *window, int button, int action, int mods);
        static void mouseCallback(GLFWWindow *window, double xpos, double ypos);
        static void scrollCallback(GLFWWindow *window, double xoff, double yoff);

    private:
        GLFWWindow *m_window;
    };
}