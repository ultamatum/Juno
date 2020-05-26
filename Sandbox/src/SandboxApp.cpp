#include <Juno.h>

#include "imgui/imgui.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Platform/OpenGL/OpenGLShader.h"

class ExampleLayer : public Juno::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
		{
			m_SquareVA.reset(Juno::VertexArray::Create());

			float squareVertices[5* 4] = {
				 -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
				  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
				  0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
				 -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
			};

			Juno::Ref<Juno::VertexBuffer> squareVB;
			squareVB.reset(Juno::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Juno::ShaderDataType::Float3, "a_Position" },
				{ Juno::ShaderDataType::Float2, "a_Texcoord"}
			});
			m_SquareVA->AddVertexBuffer(squareVB);

			unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			Juno::Ref<Juno::IndexBuffer> squareIB;
			squareIB.reset(Juno::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
			m_SquareVA->SetIndexBuffer(squareIB);

			std::string flatColourShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}

		)";

			std::string flatColourShaderfragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Colour;

			void main()
			{
				color = vec4(u_Colour, 1.0f);
			}
		)";

			m_FlatColourShader = Juno::Shader::Create("Flat Colour", flatColourShaderVertexSrc, flatColourShaderfragmentSrc);

			auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

			m_Texture = Juno::Texture2D::Create("assets/textures/Checkerboard.png");
			m_LogoTexture = Juno::Texture2D::Create("assets/textures/Logo.png");

			std::dynamic_pointer_cast<Juno::OpenGLShader>(textureShader)->Bind();
			std::dynamic_pointer_cast<Juno::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
		}

		void OnUpdate(Juno::Timestep ts) override
		{
			if (Juno::Input::IsKeyPressed(JUNO_KEY_A))
				m_CameraPosition.x -= m_CameraMoveSpeed * ts;
			else if (Juno::Input::IsKeyPressed(JUNO_KEY_D))
				m_CameraPosition.x += m_CameraMoveSpeed * ts;

			if (Juno::Input::IsKeyPressed(JUNO_KEY_W))
				m_CameraPosition.y += m_CameraMoveSpeed * ts;
			else if (Juno::Input::IsKeyPressed(JUNO_KEY_S))
				m_CameraPosition.y -= m_CameraMoveSpeed * ts;

			if (Juno::Input::IsKeyPressed(JUNO_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			else if (Juno::Input::IsKeyPressed(JUNO_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;

			Juno::RenderCommand::SetClearColour({ 0.1f, 0.1f, 0.1f, 1 });
			Juno::RenderCommand::Clear();
			
			m_Camera.SetPosition(m_CameraPosition);
			m_Camera.SetRotation(m_CameraRotation);

			Juno::Renderer::BeginScene(m_Camera);

			static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->Bind();
			std::dynamic_pointer_cast<Juno::OpenGLShader>(m_FlatColourShader)->UploadUniformFloat3("u_Colour", m_SquareColour);

			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++)
				{
					glm::vec3 pos(0.11f * x, 0.11f * y, 0.0f);

					pos.x -= ((0.11f * 20) / 2);
					pos.y -= ((0.11f * 20) / 2);

					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					
					Juno::Renderer::Submit(m_FlatColourShader, m_SquareVA, transform);
				}
			}

			auto textureShader = m_ShaderLibrary.Get("Texture");

			m_Texture->Bind();
			Juno::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5)));
			m_LogoTexture->Bind();
			Juno::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5)));

			Juno::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{
			ImGui::Begin("Settings");

			ImGui::ColorEdit3("Square Colour", glm::value_ptr(m_SquareColour));

			ImGui::End();
		}

		void OnEvent(Juno::Event& event) override
		{

		}
	private:
		Juno::ShaderLibrary m_ShaderLibrary;

		Juno::Ref<Juno::Shader> m_FlatColourShader;
		Juno::Ref<Juno::VertexArray> m_SquareVA;

		Juno::Ref<Juno::Texture2D> m_Texture, m_LogoTexture;

		Juno::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 1;
		
		float m_CameraRotation = 0;
		float m_CameraRotationSpeed = 30;

		glm::vec3 m_SquareColour = {0.2f, 0.3f, 0.8f};
};

class Sandbox : public Juno::Application
{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}

		~Sandbox()
		{

		}
};

Juno::Application* Juno::CreateApplication()
{
	return new Sandbox();
}