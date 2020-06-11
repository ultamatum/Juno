#pragma once

#include "Juno.h"

#include "ParticleSystem.h"

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
		Juno::Ref<Juno::Texture2D> m_CheckerboardTexture;

		ParticleSystem m_ParticleSystem;
		ParticleProps m_Particle;
};