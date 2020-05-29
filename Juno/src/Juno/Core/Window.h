#pragma once

#include "junopch.h"

#include "Juno/Core/Core.h"
#include "Juno/Events/Event.h"

namespace Juno
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Juno Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//Interface representing a desktop system based Window
	class JUNO_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVsync(bool enabled) = 0;
			virtual bool IsVsync() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}