#include "GLFWWindow.h"

#include "../GraphicsAPI.h"

#ifdef FL_GRAPHICS_GLFW

#include "../../glad/include/glad/glad.h"
#if defined(__linux__)
#include <GLFW/glfw3.h>
#elif defined(_WIN64)
#include <GL/GLFW/glfw3.h>
#endif
#include "../../debug/Exception.h"
#include "../../io/ImageSaver.h"
#include <cstring>

namespace fl
{

	GLFWWindow::GLFWWindow() : Window(INPUT_GLFW), m_window(nullptr)
	{
	}

	GLFWWindow::~GLFWWindow()
	{
	}

	void GLFWWindow::initialize(cString title, ui16f width, ui16f height, bool fullscreen, bool resizable, const VerticalSync &vsync)
	{
		GLFWmonitor *monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode *mode = glfwGetVideoMode(monitor);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_DEPTH_BITS, mode->refreshRate);
		glfwWindowHint(GLFW_DOUBLEBUFFER, 1);
		glfwWindowHint(GLFW_RESIZABLE, resizable ? 1 : 0);

		if (width == WINDOW_RES)
			width = mode->width;
		if (height == WINDOW_RES)
			height = mode->height;

		m_window = glfwCreateWindow(width, height, title, fullscreen ? monitor : nullptr, nullptr);

		if (m_window == nullptr)
		{
			log::fatal("Could not create GLFW window");
			exception::crash();
		}

		glfwMakeContextCurrent(m_window);

		if (!gladLoadGL())
		{
			log::fatal("Could not initialize glad");
			exception::crash();
		}

		glfwSetWindowPos(m_window, mode->width / 2 - width / 2, mode->height / 2 - height / 2);
		glfwSwapInterval((int)vsync);

		log::info("OpenGL context information:\n\n", "Vendor: ", reinterpret_cast<cString>(glGetString(GL_VENDOR)), "\n", "GPU: ", reinterpret_cast<cString>(glGetString(GL_RENDERER)), "\n", "OpenGL Version: ", reinterpret_cast<cString>(glGetString(GL_VERSION)), "\n");

		glfwSetWindowUserPointer(m_window, (void *)this);

		glfwSetKeyCallback(m_window, keyCallback);
		glfwSetMouseButtonCallback(m_window, buttonCallback);
		glfwSetCursorPosCallback(m_window, mouseCallback);
		glfwSetScrollCallback(m_window, scrollCallback);
	}

	void GLFWWindow::cleanup()
	{
		glfwDestroyWindow(m_window);
	}

	void GLFWWindow::update()
	{
		m_input.preUpdate();
		glfwPollEvents();
		m_input.postUpdate();
	}

	void GLFWWindow::swap()
	{
		glfwSwapBuffers(m_window);
	}

	void GLFWWindow::bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);
		glViewport(0, 0, width, height);
	}

	bool GLFWWindow::isCloseRequested()
	{
		return glfwWindowShouldClose(m_window) != 0;
	}

	ui16f GLFWWindow::getWidth() const
	{
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);
		return width;
	}

	ui16f GLFWWindow::getHeight() const
	{
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);
		return height;
	}

	f32 GLFWWindow::getAspectRatio() const
	{
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);
		return static_cast<f32>(width) / static_cast<f32>(height);
	}

	bool GLFWWindow::isMouseGrabbed() const
	{
		return glfwGetInputMode(m_window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
	}

	void GLFWWindow::setMouseGrabbed(bool grabbed) const
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, grabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
	}

	void GLFWWindow::captureScreenshot(cString file) const
	{
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);

		ui32f pixelSize = 3;

		ui8 *pixels = new ui8[pixelSize * width * height];

		i32 readBuffer;
		glGetIntegerv(GL_READ_BUFFER, &readBuffer);
		glReadBuffer(GL_FRONT);
		glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		glReadBuffer(readBuffer);

		ui8 *flippedPixels = new ui8[pixelSize * width * height];
		for (ui32f y = 0; y < static_cast<ui32f>(height); y++)
		{
			memcpy(flippedPixels + (pixelSize * y * width), pixels + (pixelSize * (height - y - 1) * width), width * pixelSize);
		}
		delete[] pixels;

		io::savePNG(file, flippedPixels, width, height, FORMAT_RGB8);
		delete[] flippedPixels;
	}

	void GLFWWindow::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		GLFWWindow *w = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
		w->m_input.addKeyEvent(key, action != GLFW_RELEASE);
	}

	void GLFWWindow::buttonCallback(GLFWwindow *window, int button, int action, int mods)
	{
		GLFWWindow *w = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
		w->m_input.addButtonEvent(button, action != GLFW_RELEASE);
	}

	void GLFWWindow::mouseCallback(GLFWwindow *window, double xpos, double ypos)
	{
		GLFWWindow *w = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
		w->m_input.addMousePositionEvent(xpos, ypos);
	}

	void GLFWWindow::scrollCallback(GLFWwindow *window, double xoff, double yoff)
	{
		GLFWWindow *w = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
		w->m_input.addMouseScrollEvent(yoff);
	}

}

#endif