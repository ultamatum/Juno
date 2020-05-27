#pragma once

#include "Juno.h"

class Sandbox2D : public Juno::Layer
{
	public:
		Sandbox2D();
		virtual ~Sandbox2D() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		void OnUpdate(Juno::Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Juno::Event& event) override;

	private:
		Juno::OrthographicCameraController m_CameraController;

		//Temp
		Juno::Ref<Juno::VertexArray> m_SquareVA;
		Juno::Ref<Juno::Shader> m_FlatColourShader;

		glm::vec4 m_SquareColour = { 0.2f, 0.3f, 0.8f, 1.0f };
};