#pragma once
#include <SDL.h>
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
	class Drizzle2D_API Window {
	public:
		Window();
		void CreateWin();
		bool mainloop();
		SDL_Renderer* renderer;
		SDL_Window* window;
		char* WinTitle = (char*)"Drizzle2D Game";
		int bgcolor[4] = { 255, 255, 255, 255 };
		int WinX = SDL_WINDOWPOS_CENTERED;
		int WinY = SDL_WINDOWPOS_CENTERED;
		int WinWidth = 800;
		int WinHeight = 600;
		SDL_WindowFlags WinFlags = SDL_WINDOW_SHOWN;
	};
}