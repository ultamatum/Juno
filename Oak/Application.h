#pragma once

#include "Core.h"

namespace Oak
{
	class __declspec(dllexport) Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};
}

