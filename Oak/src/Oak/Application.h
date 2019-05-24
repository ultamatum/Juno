#pragma once

#include "Core.h"

namespace Oak
{
	class OAK_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

