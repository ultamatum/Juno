#pragma once

#include "Oak/Window.h"
#include "Oak/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Oak
{
	class WindowsWindow : public Window
	{
		public:
			WindowsWindow(const WindowProps& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }

			//Window attributes
			inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
			void SetVsync(bool enabled) override;
			bool IsVsync() const override;

			inline virtual void* GetNativeWindow() const { return m_Window; }

		private:
			virtual void Init(const WindowProps& props);
			virtual void ShutDown();

		private:
			GLFWwindow* m_Window;
			GraphicsContext* m_Context;

			struct WindowData
			{
				std::string Title;
				unsigned int Width, Height;
				bool VSync;
				EventCallbackFn EventCallback;
			};

			WindowData m_Data;
	};
}