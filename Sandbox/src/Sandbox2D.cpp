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
	m_SquareVA = Juno::VertexArray::Create();

	float squareVertices[3 * 4] = {
		 -0.5f, -0.5f, 0.0f,
		  0.5f, -0.5f, 0.0f,
		  0.5f,  0.5f, 0.0f,
		 -0.5f,  0.5f, 0.0f
	};

	Juno::Ref<Juno::VertexBuffer> squareVB;
	squareVB.reset(Juno::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Juno::ShaderDataType::Float3, "a_Position" }
	});
	m_SquareVA->AddVertexBuffer(squareVB);

	unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Juno::Ref<Juno::IndexBuffer> squareIB;
	squareIB.reset(Juno::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColourShader = Juno::Shader::Create("assets/shaders/FlatColour.glsl");
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

	Juno::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->Bind();
	std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->UploadUniformFloat4("u_Colour", m_SquareColour);

	Juno::Renderer::Submit(m_FlatColourShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5)));

	Juno::Renderer::EndScene();
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
