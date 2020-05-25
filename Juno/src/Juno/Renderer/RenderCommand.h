#pragma once

#include "RendererAPI.h"

namespace Juno
{
	class RenderCommand
	{
		public:
			inline static void Init() { s_RendererAPI->Init(); }
			inline static void SetClearColour(const glm::vec4& colour) { s_RendererAPI->SetClearColor(colour); };
			inline static void Clear() { s_RendererAPI->Clear(); };
			inline static void DrawIndexed(const Ref<VertexArray>& vertexArray) { s_RendererAPI->DrawIndexed(vertexArray); };

		private:
			static RendererAPI* s_RendererAPI;
	};
}