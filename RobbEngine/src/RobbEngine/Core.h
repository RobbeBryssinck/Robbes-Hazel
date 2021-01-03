#pragma once

#ifdef RE_PLATFORM_WINDOWS
	#ifdef RE_BUILD_DLL
		#define ROBBENGINE_API __declspec(dllexport)
	#else
		#define ROBBENGINE_API __declspec(dllimport)
	#endif
#else
	#error RobbEngine only supports Windows!
#endif
