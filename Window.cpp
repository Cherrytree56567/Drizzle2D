#include "Window.h"

namespace Drizzle2D {
	Window::Window() {
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			SDL_Log( "Drizzle2D", "Failed to initialize SDL: %s", SDL_GetError());
		}
	}

	void Window::CreateWin() {
		window = SDL_CreateWindow(WinTitle, WinX, WinY, WinWidth, WinHeight, WinFlags);
		if (window == NULL) {
			SDL_Log("Drizzle2D", "Failed to create window: %s", SDL_GetError());
			SDL_Quit();
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			SDL_Log("Drizzle2D", "Failed to create renderer: %s", SDL_GetError());
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}

	bool Window::mainloop() {
		SDL_RenderPresent(renderer);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
				return true;
			}
		}

		SDL_SetRenderDrawColor(renderer, bgcolor[0], bgcolor[1], bgcolor[2], bgcolor[3]);
		SDL_RenderClear(renderer);
		return false;
	}
}