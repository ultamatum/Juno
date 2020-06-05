#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{
	JUNO_PROFILE_FUNCTION();

	m_CheckerboardTexture = Juno::Texture2D::Create("assets/textures/Checkerboard.png");

	//Init particle
	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };
}

void Sandbox2D::OnDetach()
{
	JUNO_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(Juno::Timestep ts)
{
	JUNO_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Juno::Renderer2D::ResetStats();
	{
		JUNO_PROFILE_SCOPE("Renderer Prep");
		Juno::RenderCommand::SetClearColour({ 0.1f, 0.1f, 0.1f, 1 });
		Juno::RenderCommand::Clear();
	}

	{
		JUNO_PROFILE_SCOPE("Renderer Draw");
		
		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		Juno::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Juno::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Juno::Renderer2D::DrawRotatedQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, glm::radians(rotation), { 0.2f, 0.3f, 0.8f, 1.0f });

		Juno::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1 }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Juno::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CheckerboardTexture, 20.0f);

		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 colour = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Juno::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, colour);
			}
		}

		Juno::Renderer2D::EndScene();
	}

	if (Juno::Input::IsMouseButtonPressed(JUNO_MOUSE_BUTTON_LEFT))
	{
		auto [x, y] = Juno::Input::GetMousePosition();
		auto width = Juno::Application::Get().GetWindow().GetWidth();
		auto height = Juno::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
	}

	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());
}

void Sandbox2D::OnImGuiRender()
{
	JUNO_PROFILE_FUNCTION();

	auto stats = Juno::Renderer2D::GetStats();

	ImGui::Begin("Settings");

	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls %d", stats.DrawCalls);
	ImGui::Text("Quad Count: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::End();
}

void Sandbox2D::OnEvent(Juno::Event& e)
{
	m_CameraController.OnEvent(e);
}
