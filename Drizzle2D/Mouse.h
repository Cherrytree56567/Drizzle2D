#pragma once
#include <SDL.h>
#include <windows.h>
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
	class Drizzle2D_API Mouse {
	public:
		bool IsMouseLeftPressed(SDL_Window* window);
		bool IsMouseLeftReleased(SDL_Window* window);
		bool IsMouseLeftHeld(SDL_Window* window);
		bool IsMouseRightPressed(SDL_Window* window);
		bool IsMouseRightReleased(SDL_Window* window);
		bool IsMouseRightHeld(SDL_Window* window);
		int GetMouseX();
		int GetMouseY();
		int GetScrollWheelDelta();
	};
}