#pragma once

#include "Core.h"

#include "Window.h"
#include "Oak/LayerStack.h"
#include "Oak/Events/Event.h"
#include "Oak/Events/ApplicationEvent.h"

namespace Oak
{
	class OAK_API Application
	{
		public:
			Application();
			virtual ~Application();
			
			void Run();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			inline Window& GetWindow() { return *m_Window; }

			inline static Application& Get() { return *s_Instance; }
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			LayerStack m_LayerStack;

		private:
			static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

