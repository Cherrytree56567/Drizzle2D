#pragma once
#include <Windows.h>
#include <stdio.h>
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
	typedef void (*thread_function_t)(void);
	Drizzle2D_API DWORD WINAPI ThreadFunc(LPVOID lpParam);
	Drizzle2D_API void multithread_function(thread_function_t thread_func);
}
