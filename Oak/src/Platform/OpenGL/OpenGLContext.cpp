#include "okpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Oak
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		OK_CORE_ASSERT(windowHandle, "Window handle is null")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OK_CORE_ASSERT(status, "Failed to initialize Glad!");

		OK_CORE_INFO("OpenGL Info:");
		OK_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		OK_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		OK_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}