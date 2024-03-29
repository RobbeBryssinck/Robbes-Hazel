#pragma once

#ifdef RE_PLATFORM_WINDOWS
#if RE_DYNAMIC_LINK
	#ifdef RE_BUILD_DLL
		#define ROBBENGINE_API __declspec(dllexport)
	#else
		#define ROBBENGINE_API __declspec(dllimport)
	#endif
#else
	#define ROBBENGINE_API
#endif
#else
	#error RobbEngine only supports Windows!
#endif

#ifdef RE_DEBUG
	#define RE_ENABLE_ASSERTS
#endif

#ifdef RE_ENABLE_ASSERTS
	#define RE_ASSERT(x, ...) { if(!(x)) { RE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RE_CORE_ASSERT(x, ...) { if(!(x)) { RE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RE_ASSERT(x, ...)
	#define RE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
