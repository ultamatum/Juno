#include "okpch.h"
#include "Application.h"

#include "Oak/Events/ApplicationEvent.h"
#include "Oak/Log.h"

namespace Oak
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}