/*
*	Juno Application class
*	Used to generate an application object and manage layers
*/

#pragma once

#include "Core.h"

#include "Window.h"
#include "Juno/Core/LayerStack.h"
#include "Juno/Events/Event.h"
#include "Juno/Events/ApplicationEvent.h"

#include "Juno/Core/Timestep.h"

#include "Juno/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Juno
{
	class Application
	{
		public:
			Application(const std::string& name = "Juno App");
			virtual ~Application();
			
			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			inline Window& GetWindow() { return *m_Window; }

			void Close();

			ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

			inline static Application& Get() { return *s_Instance; }
			std::string CorrectFilePath(const std::string& path);

		private:
			void Run();
			bool OnWindowClose(WindowCloseEvent& e);
			bool OnWindowResize(WindowResizeEvent& e);

			Scope<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			bool m_Minimized = false;
			LayerStack m_LayerStack;
			float m_LastFrameTime = 0.0f;

		private:
			static Application* s_Instance;
			std::string m_BaseDirectory;
			friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

