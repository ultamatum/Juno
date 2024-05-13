#include "junopch.h"
#include "Application.h"

#include "Juno/Renderer/Renderer.h"

#include "Input.h"

#include <GLFW/glfw3.h>

namespace Juno
{
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
	{
		JUNO_PROFILE_FUNCTION();

		//Makes sure there isn't a duplicate application being created
		JUNO_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		//Creates the window object
		m_Window = Window::Create(WindowProps(name));
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Init();

		//Initializes Dear ImGui used for overlay and debugging
		m_ImGuiLayer = new ImGuiLayer;
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() 
	{
		JUNO_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	//Add a layer to the layer stack
	void Application::PushLayer(Layer* layer)
	{
		JUNO_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	//Adds an overlay to the layer stack (rendered last)
	void Application::PushOverlay(Layer* layer)
	{
		JUNO_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach(); 
	}

	void Application::Close()
	{
		m_Running = false;
	}

		//Dispatches event to the relevant callback function
	void Application::OnEvent(Event& e)
	{
		JUNO_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

		//Makes sure every layer has handled the event
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			if (e.Handled)
				break;
			(*--it)->OnEvent(e);
		}
	}

	//Program loop
	void Application::Run()
	{
		JUNO_PROFILE_FUNCTION();

		while (m_Running)  
		{
			JUNO_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					JUNO_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}

				{
					JUNO_PROFILE_SCOPE("LayerStack OnImGuiRender");

					m_ImGuiLayer->Begin();
					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
					m_ImGuiLayer->End();
				}
			}

			m_Window->OnUpdate();
		}
	}

	std::string Application::CorrectFilePath(const std::string& path)
	{
		#if defined(JUNO_DEBUG) || defined(JUNO_RELEASE)
			if (std::filesystem::exists(path))
				return path;

			auto check_path = std::filesystem::path(".") / m_BaseDirectory / path;
			if (std::filesystem::exists(check_path))
				return check_path.string();

			check_path = std::filesystem::path("../../..") / m_BaseDirectory / path;	//Decend to project directory from executable's directory
			if (std::filesystem::exists(check_path))
				return check_path.string();
		#endif
		return path;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		JUNO_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}
