#pragma once

#include "Juno.h"

namespace Juno::Persephone
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
	};
}
