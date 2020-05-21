#include <Oak.h>

#include "imgui/imgui.h"

class ExampleLayer : public Oak::Layer
{
	public:
		ExampleLayer()
			: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
		{
			m_VertexArray.reset(Oak::VertexArray::Create());

			float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
				 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
				 0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
			};

			std::shared_ptr<Oak::VertexBuffer> vertexBuffer;
			vertexBuffer.reset(Oak::VertexBuffer::Create(vertices, sizeof(vertices)));

			Oak::BufferLayout layout = {
				{ Oak::ShaderDataType::Float3, "a_Position" },
				{ Oak::ShaderDataType::Float4, "a_Colour" }
			};

			vertexBuffer->SetLayout(layout);
			m_VertexArray->AddVertexBuffer(vertexBuffer);

			unsigned int indices[3] = { 0, 1, 2 };
			std::shared_ptr<Oak::IndexBuffer> indexBuffer;
			indexBuffer.reset(Oak::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
			m_VertexArray->SetIndexBuffer(indexBuffer);

			m_SquareVA.reset(Oak::VertexArray::Create());

			float squareVertices[3 * 4] = {
				 -0.75f, -0.75f, 0.0f,
				  0.75f, -0.75f, 0.0f,
				  0.75f,  0.75f, 0.0f,
				 -0.75f,  0.75f, 0.0f
			};

			std::shared_ptr<Oak::VertexBuffer> squareVB;
			squareVB.reset(Oak::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
			squareVB->SetLayout({
				{ Oak::ShaderDataType::Float3, "a_Position" }
								});
			m_SquareVA->AddVertexBuffer(squareVB);

			unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
			std::shared_ptr<Oak::IndexBuffer> squareIB;
			squareIB.reset(Oak::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
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

			m_Shader.reset(new Oak::Shader(vertexSrc, fragmentSrc));

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

			m_BlueShader.reset(new Oak::Shader(blueShaderVertexSrc, blueShaderfragmentSrc));
		}

		void OnUpdate() override
		{
			if (Oak::Input::IsKeyPressed(OK_KEY_A))
				m_CameraPosition.x -= m_CameraMoveSpeed;
			else if (Oak::Input::IsKeyPressed(OK_KEY_D))
				m_CameraPosition.x += m_CameraMoveSpeed;

			if (Oak::Input::IsKeyPressed(OK_KEY_W))
				m_CameraPosition.y += m_CameraMoveSpeed;
			else if (Oak::Input::IsKeyPressed(OK_KEY_S))
				m_CameraPosition.y -= m_CameraMoveSpeed;

			if (Oak::Input::IsKeyPressed(OK_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed;
			else if (Oak::Input::IsKeyPressed(OK_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed;

			Oak::RenderCommand::SetClearColour({ 0.1f, 0.1f, 0.1f, 1 });
			Oak::RenderCommand::Clear();
			
			m_Camera.SetPosition(m_CameraPosition);
			m_Camera.SetRotation(m_CameraRotation);

			Oak::Renderer::BeginScene(m_Camera);
			
			Oak::Renderer::Submit(m_BlueShader, m_SquareVA);
			
			Oak::Renderer::Submit(m_Shader, m_VertexArray);
			
			Oak::Renderer::EndScene();
		}

		virtual void OnImGuiRender() override
		{

		}

		void OnEvent(Oak::Event& event) override
		{

		}
	private:
		std::shared_ptr<Oak::Shader> m_Shader;
		std::shared_ptr<Oak::VertexArray> m_VertexArray;

		std::shared_ptr<Oak::Shader> m_BlueShader;
		std::shared_ptr<Oak::VertexArray> m_SquareVA;

		Oak::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 0.1;
		
		float m_CameraRotation = 0;
		float m_CameraRotationSpeed = 2;
};

class Sandbox : public Oak::Application
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

Oak::Application* Oak::CreateApplication()
{
	return new Sandbox();
}