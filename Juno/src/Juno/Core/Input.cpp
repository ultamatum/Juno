#include "junopch.h"
#include "Juno/Core/Input.h"

#ifdef JUNO_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Juno
{
	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef JUNO_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			JUNO_CORE_ASSERT(false, "Unknown Platform!");
			return nullptr;
		#endif
	}
}
