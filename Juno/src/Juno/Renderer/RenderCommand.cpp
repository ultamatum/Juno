#include "junopch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Juno
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();
}