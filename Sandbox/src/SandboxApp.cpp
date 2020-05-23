#include <Juno.h>

#include "imgui/imgui.h"

class ExampleLayer : public Juno::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
		{
			m_VertexArray.reset(Juno::VertexArray::Create());

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
				 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
				 0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
			};

			std::shared_ptr<Juno::VertexBuffer> vertexBuffer;
			vertexBuffer.reset(Juno::VertexBuffer::Create(vertices, sizeof(vertices)));

			Juno::BufferLayout layout = {
				{ Juno::ShaderDataType::Float3, "a_Position" },
				{ Juno::ShaderDataType::Float4, "a_Colour" }
			};

			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);

			unsigned int indices[3] = { 0, 1, 2 };
			std::shared_ptr<Juno::IndexBuffer> indexBuffer;
			indexBuffer.reset(Juno::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(indexBuffer);

			m_SquareVA.reset(Juno::VertexArray::Create());

			float squareVertices[3 * 4] = {
				 -0.75f, -0.75f, 0.0f,
				  0.75f, -0.75f, 0.0f,
				  0.75f,  0.75f, 0.0f,
				 -0.75f,  0.75f, 0.0f
			};

			std::shared_ptr<Juno::VertexBuffer> squareVB;
			squareVB.reset(Juno::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Juno::ShaderDataType::Float3, "a_Position" }
								});
			m_SquareVA->AddVertexBuffer(squareVB);

			unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			std::shared_ptr<Juno::IndexBuffer> squareIB;
			squareIB.reset(Juno::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
			m_SquareVA->SetIndexBuffer(squareIB);

			std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Colour;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Colour;

			void main()
			{
				v_Position = a_Position;
				v_Colour = a_Colour;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}

		)";

			std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Colour;

			void main()
			{
				color = v_Colour;
			}

		)";

			m_Shader.reset(new Juno::Shader(vertexSrc, fragmentSrc));

			std::string blueShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}

		)";

			std::string blueShaderfragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

			m_BlueShader.reset(new Juno::Shader(blueShaderVertexSrc, blueShaderfragmentSrc));
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
			
			Juno::Renderer::Submit(m_BlueShader, m_SquareVA);
			
			Juno::Renderer::Submit(m_Shader, m_VertexArray);
			
			Juno::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{

		}

		void OnEvent(Juno::Event& event) override
		{

		}
	private:
		std::shared_ptr<Juno::Shader> m_Shader;
		std::shared_ptr<Juno::VertexArray> m_VertexArray;

		std::shared_ptr<Juno::Shader> m_BlueShader;
		std::shared_ptr<Juno::VertexArray> m_SquareVA;

		Juno::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 1;
		
		float m_CameraRotation = 0;
		float m_CameraRotationSpeed = 30;
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