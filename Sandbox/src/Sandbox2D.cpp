#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{}

void Sandbox2D::OnAttach()
{

}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Juno::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Juno::RenderCommand::SetClearColour({ 0.1f, 0.1f, 0.1f, 1 });
	Juno::RenderCommand::Clear();

	Juno::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Juno::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });

	Juno::Renderer2D::EndScene();

	//TODO: Add Shader::SetMat4, Shader::SetFloat4
	//std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->Bind();
	//std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->UploadUniformFloat4("u_Colour", m_SquareColour);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Colour", glm::value_ptr(m_SquareColour));
	ImGui::End();
}

void Sandbox2D::OnEvent(Juno::Event& e)
{
	m_CameraController.OnEvent(e);
}
