#include "junopch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Juno
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}