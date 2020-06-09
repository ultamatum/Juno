#pragma once

#include "Camera.h"

#include "Texture.h"
#include "SubTexture2D.h"

namespace Juno
{
	class Renderer2D
	{
		public:
			static void Init();
			static void Shutdown();

			static void BeginScene(const OrthographicCamera& camera);
			static void EndScene();
			static void Flush();

			//Primitives
			static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& colour) { DrawQuad({position.x, position.y, 0.0f}, size, colour); }
			static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour);
			static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f)) { DrawQuad(position, size, texture, tilingFactor, tintColour); }
			static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));
			static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subTexture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f)) { DrawQuad(position, size, subTexture, tilingFactor, tintColour); }
			static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subTexture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

			static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& colour) { DrawRotatedQuad({position.x, position.y, 0.0f}, size, rotation, colour); };
			static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& colour);
			static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f)) { DrawRotatedQuad(position, size, rotation, texture, tilingFactor, tintColour); }
			static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));
			static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subTexture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f)) { DrawRotatedQuad(position, size, rotation, subTexture, tilingFactor, tintColour); }
			static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subTexture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));
		
			//Stats
			struct Statistics
			{
				uint32_t DrawCalls = 0;
				uint32_t QuadCount = 0;

				uint32_t GetTotalVertexCount() { return QuadCount * 4; };
				uint32_t GetTotalIndexCount() { return QuadCount * 6; };
			};

			static void ResetStats();
			static Statistics GetStats();

		private:
			static void FlushAndReset();
			static void BuildQuad(const glm::vec3& position, float rotation, const glm::vec2& size, float textureIndex, float tilingFactor, const glm::vec4& colour, const glm::vec2 textureCoords[4]);
			static float AddTexToIndex(const Ref<Texture2D>& texture);
	};
}