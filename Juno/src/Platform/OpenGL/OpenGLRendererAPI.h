#pragma once

#include "Juno/Renderer/RendererAPI.h"

namespace Juno
{
	class OpenGLRendererAPI : public RendererAPI
	{
		public:
			virtual void SetClearColor(const glm::vec4& colour) override;
			virtual void Clear() override;

			virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}