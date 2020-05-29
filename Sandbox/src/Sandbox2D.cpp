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
	{
		JUNO_PROFILE_SCOPE("Renderer Prep");
		Juno::RenderCommand::SetClearColour({ 0.1f, 0.1f, 0.1f, 1 });
		Juno::RenderCommand::Clear();
	}

	{
		JUNO_PROFILE_SCOPE("Renderer Draw");
		Juno::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Juno::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Juno::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });

		Juno::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1 }, { 10.0f, 10.0f }, m_CheckerboardTexture);

		Juno::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	JUNO_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Colour", glm::value_ptr(m_SquareColour));
	ImGui::End();
}

void Sandbox2D::OnEvent(Juno::Event& e)
{
	m_CameraController.OnEvent(e);
}
