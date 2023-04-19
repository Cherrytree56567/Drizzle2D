#include "Sprite.h"

namespace Drizzle2D {
	void TexturizeSpriteBMP(Sprite* spr, Window* wins, char* filename) {
		spr->image = IMG_Load(filename);
		if (!spr->image) {
			std::cout << "Error loading image "  << filename << ": " << SDL_GetError() << std::endl;
			exit(0);
		}
		spr->img = SDL_CreateTextureFromSurface(wins->renderer, spr->image);
	}
	void renderSprite(Sprite* spr, Window* wins) {
		int textureWidth, textureHeight;
		if (SDL_QueryTexture(spr->img, NULL, NULL, &textureWidth, &textureHeight) != 0) {
			printf("Error getting texture size: %s\n", SDL_GetError());
		}
		int width = wins->WinWidth * spr->ScaleW;
		int height = wins->WinHeight * spr->ScaleH;
		SDL_Rect destRect = { spr->PosX, spr->PosY, width, height };
		SDL_RenderCopyEx(wins->renderer, spr->img, NULL, &destRect, spr->rotationTurn, NULL, SDL_FLIP_NONE);
	}
}