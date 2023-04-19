#pragma once
#include "Sprite.h"
#include <vector>
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
	class Drizzle2D_API Rendering {
	private:
		Window* wins;
	public:
		std::vector<Sprite> RenderingArray;
		void Render(Window* wins);
		Sprite FindSprite(char* Csnm);
		void AddSprite(Sprite sp);
		void DeleteSprite(char* Csnm);
		void ChangeSprite(Sprite s);
	};
}