#pragma once

// #ifdef FL_PLATFORM_LINUX || FL_PLATFORM_UNIX
// #include <GLFW/glfw3.h>
// #elif FL_PLATFORM_WINDOWS_64 || FL_PLATFORM_WINDOWS_32
// #include <GL/GLFW/glfw3.h>
// #endif 

#include <Window.h>

struct GLFWwindow;

namespace fl 
{
    class FL_API GLFWWINDOW : public Window 
    {
    public:
		GLFWWindow();
		~GLFWWindow();

		void initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VSync& vsync) override;
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
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void buttonCallback(GLFWwindow* window, int button, int action, int mods);
		static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
		static void scrollCallback(GLFWwindow* window, double xoff, double yoff);
	private:
		GLFWwindow* m_window;

    };
}