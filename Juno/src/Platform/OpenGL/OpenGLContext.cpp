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
		JUNO_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JUNO_CORE_ASSERT(status, "Failed to initialize Glad!");

		JUNO_CORE_INFO("OpenGL Info:");
		JUNO_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		JUNO_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		JUNO_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		JUNO_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Juno requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		JUNO_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
