#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#ifdef BR_BUILD_DLL
		#define BARREL_API __declspec(dllexport)
	#else
		#define BARREL_API __declspec(dllimport)
	#endif
#else
	#error Baryla toczy sie tylko w windowsie.
#endif