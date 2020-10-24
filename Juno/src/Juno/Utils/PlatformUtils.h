#pragma once

#include <string>

namespace Juno
{
	class FileDialogs
	{
		public:
			// Returns empty string if cancelled
			static std::string OpenFile(const char* filter);
			static std::string SaveFile(const char* filter);
	};
}
