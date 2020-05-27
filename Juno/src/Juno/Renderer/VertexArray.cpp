#include "junopch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Juno
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		JUNO_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return CreateRef<OpenGLVertexArray>();
		}

		JUNO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}