#include "Application.h"

#include "Oak/Events/ApplicationEvent.h"
#include "Oak/Log.h"

namespace Oak
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		OK_TRACE(e);

		while (true);
	}
}