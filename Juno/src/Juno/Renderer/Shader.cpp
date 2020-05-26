#include "junopch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Juno
{
	Juno::Shader* Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		JUNO_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return new OpenGLShader(filepath);
		}

		JUNO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		JUNO_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return new OpenGLShader(vertexSrc, fragSrc);
		}

		JUNO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}