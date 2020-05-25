#include "junopch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Juno
{
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		JUNO_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return std::make_shared<OpenGLTexture2D>(path);
		}

		JUNO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}


