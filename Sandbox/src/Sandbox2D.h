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
		Juno::Ref<Juno::Texture2D> m_SpriteSheet;
		Juno::Ref<Juno::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree;

		ParticleSystem m_ParticleSystem;
		ParticleProps m_Particle;

		uint32_t m_MapWidth, m_MapHeight;
		std::unordered_map<char, Juno::Ref<Juno::SubTexture2D>> s_TextureMap;

		glm::vec3 barPos = { 10.0f, 10.0f, 0.5f };
};