#include "junopch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Juno
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		JUNO_CORE_ASSERT(windowHandle, "Window handle is null")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JUNO_CORE_ASSERT(status, "Failed to initialize Glad!");

		JUNO_CORE_INFO("OpenGL Info:");
		JUNO_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		JUNO_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		JUNO_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
