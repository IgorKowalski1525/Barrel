#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#if BR_DYNAMIC_LINK
		#ifdef BR_BUILD_DLL
			#define BARREL_API __declspec(dllexport)
		#else
			#define BARREL_API __declspec(dllimport)
		#endif
	#else
		#define BARREL_API
	#endif
#else
	#error Baryla toczy sie tylko w windowsie.
#endif

#ifdef BR_ENABLE_ASSERTS
	#define BR_ASSERT(x, ...) {if(!(x)) {BR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BR_CORE_ASSERT(x, ...) {if(!(x)) {BR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BR_ASSERT(x, ...)
	#define BR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)