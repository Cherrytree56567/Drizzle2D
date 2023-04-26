#include "Rendering.h"
#include <algorithm>

namespace Drizzle2D {
	bool compareByPosZ(const Sprite& a, const Sprite& b) {
		return a.PosZ > b.PosZ;
	}

	void Rendering::DeleteSprite(char* Csnm) {
		int size = RenderingArray.size() - 1;
		int i = 0;
		bool t = true;
		while (t) {
			if (i > size) {
				t = false;
			}
			else {
				if (RenderingArray[i].class_name == Csnm) {
					RenderingArray.erase(RenderingArray.begin() + i);
					t = false;
				}
			}
			i++;
		}
	}

	void Rendering::ChangeSprite(Sprite s) {
		DeleteSprite(s.class_name);
		AddSprite(s);
	}

	void Rendering::Render(Window* wins) {
		int size = RenderingArray.size() - 1;
		int i = 0;
		std::sort(RenderingArray.begin(), RenderingArray.end(), compareByPosZ);
		while (true) {
			if (i > size) {
				break;
			} else {
				renderSprite(&RenderingArray[i], wins);
				i++;
			}
		}
	}
	Sprite Rendering::FindSprite(char* Csnm) {
		int size = RenderingArray.size() - 1;
		int i = 0;
		bool s = true;
		while (s) {
			if (i > size) {
				s = false;
			} else {
				if (RenderingArray[i].class_name == Csnm) {
					s = false;
					return RenderingArray[i];
				} else {
					i++;
				}
			}
		}
	}

	void Rendering::AddSprite(Sprite sp) {
		RenderingArray.push_back(sp);
	}
}