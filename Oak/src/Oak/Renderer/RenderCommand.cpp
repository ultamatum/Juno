#include "okpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Oak
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}