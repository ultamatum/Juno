#pragma once

#ifdef  OK_PLATFORM_WINDOWS
	#ifdef OK_BUILD_DLL
		#define OAK_API __declspec(dllexport)
	#else
		#define OAK_API __declspec(dllimport)
	#endif // OK_BUILD_DLL
#else
	#error Oak only supports Windows!
#endif //  OK_PLATFORM_WINDOWS
