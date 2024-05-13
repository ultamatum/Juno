#include "junopch.h"
#include "Juno/Core/Window.h"

#if defined(JUNO_PLATFORM_WINDOWS) || defined(JUNO_PLATFORM_LINUX)
	#include "Platform/Windows/WindowsWindow.h"
#endif 

namespace Juno
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
		#if defined(JUNO_PLATFORM_WINDOWS) || defined(JUNO_PLATFORM_LINUX)
			return CreateScope<WindowsWindow>(props);
		#else
			JUNO_CORE_ASSERT(false, "Unknown Platform!");
			return nullptr;
		#endif
	}
}
