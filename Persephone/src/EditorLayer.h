#pragma once

#include "Juno.h"

namespace Juno
{
	class EditorLayer : public Layer
	{
		public:
			EditorLayer();
			virtual ~EditorLayer() = default;

			virtual void OnAttach() override;
			virtual void OnDetach() override;
			void OnUpdate(Timestep ts) override;
			virtual void OnImGuiRender() override;
			void OnEvent(Event& event) override;

		private:
			OrthographicCameraController m_CameraController;

			//Temp
			Ref<Texture2D> m_CheckerboardTexture;
			Ref<Framebuffer> m_Framebuffer;

			Ref<Scene> m_ActiveScene;
			Entity m_SquareEntity;
			Entity m_CameraEntity;
			Entity m_SecondCamera;
			
			bool m_PrimaryCamera = true;

			bool m_ViewportFocused = false;
			bool m_ViewportHovered = false;
			glm::vec2 m_ViewportSize = {0.0f, 0.0f};
	};
}
