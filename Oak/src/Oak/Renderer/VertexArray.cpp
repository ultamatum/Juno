#include "okpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Oak
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:			OK_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return new OpenGLVertexArray();
		}

		OK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}