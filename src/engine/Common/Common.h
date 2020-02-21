#pragma once

// TODO: Add other OS-s
#ifdef OGLME_BUILD_ENGINE
	#define OGLME_API __declspec(dllexport)
#else
	#define OGLME_API __declspec(dllimport)
#endif
