#pragma once

// TODO: Add other OS-s
#ifdef OGLME_BUILD_ENGINE
	#define OGLME_API __declspec(dllexport)
#else
	#define OGLME_API __declspec(dllimport)
#endif

#ifdef _WIN32 
	#define FORCE_INLINE __forceinline
#elif __linux__
	#define FORCE_INLINE __attribute__((always_inline))
#else
	#define FORCE_INLINE inline
#endif

#include <GLAD/glad.h>
#include <iostream>