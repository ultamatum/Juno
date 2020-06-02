#include "junopch.h"
#include "Juno/Core/Window.h"

#ifdef JUNO_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif 

namespace Juno
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
		#ifdef JUNO_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			JUNO_CORE_ASSERT(false, "Unknown Platform!");
			return nullptr;
		#endif
	}
}
