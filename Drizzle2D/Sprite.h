#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Window.h"
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
	struct Sprite {
		SDL_Surface* image;
		SDL_Texture* img;
		char* class_name;
		int PosX = 0;
		int PosY = 0;
		int PosZ = 0;
		int rotationTurn = 0;
		double ScaleW = 1;
		double ScaleH = 1;
		int HealthMax;
		int CurrentHealth;
	};
	Drizzle2D_API void TexturizeSpriteBMP(Sprite* spr, Window* wins, char* filename);
	Drizzle2D_API void renderSprite(Sprite* spr, Window* wins);
}
