#pragma once
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>
#include <Windows.h>
#define Key_Backspace 8
#define Key_Tab 9
#define Key_Numpad_Clear 9
#define Key_Enter 13
#define Key_Shift 16
#define Key_Ctrl 17
#define Key_Alt 18
#define Key_Pause 19
#define Key_CapsLock 20
#define Key_Esc 17
#define Key_Space 32
#define Key_Page_Up 33
#define Key_Page_Down 34
#define Key_End 35
#define Key_Home 36
#define Key_Left_Arrow 37
#define Key_Up_Arrow 38
#define Key_Right_Arrow 39
#define Key_Down_Arrow 40
#define Key_Print_Screen 44
#define Key_Insert 45
#define Key_Delete 46
#define Key_0 48
#define Key_1 49
#define Key_2 50
#define Key_3 51
#define Key_4 52
#define Key_5 53
#define Key_6 54
#define Key_7 55
#define Key_8 56
#define Key_9 57
#define Key_A 65
#define Key_B 66
#define Key_C 67
#define Key_D 68
#define Key_E 69
#define Key_F 70
#define Key_G 71
#define Key_H 72
#define Key_I 73
#define Key_J 74
#define Key_K 75
#define Key_L 76
#define Key_M 77
#define Key_N 78
#define Key_O 79
#define Key_P 80
#define Key_Q 81
#define Key_R 82
#define Key_S 83
#define Key_T 84
#define Key_U 85
#define Key_V 86
#define Key_W 87
#define Key_X 88
#define Key_Y 89
#define Key_Z 90
#define Key_Left_CMD 91
#define Key_Right_Win 92
#define Key_Popup 93
#define Key_Num_0 96
#define Key_Num_1 97
#define Key_Num_2 98
#define Key_Num_3 99
#define Key_Num_4 100
#define Key_Num_5 101
#define Key_Num_6 102
#define Key_Num_7 103
#define Key_Num_8 104
#define Key_Num_9 105
#define Key_Num_Asterisk 106
#define Key_Num_Plus 107
#define Key_Num_Minus 109
#define Key_Num_Dot 110
#define Key_Num_Slash 111
#define Key_F1 112
#define Key_F2 113
#define Key_F3 114
#define Key_F4 115
#define Key_F5 116
#define Key_F6 117
#define Key_F7 118
#define Key_F8 119
#define Key_F9 120
#define Key_F10 121
#define Key_F11 122
#define Key_F12 123
#define Key_Num_Lock 144
#define Key_Scroll_Lock 145
#define Key_Left_Shift 160
#define Key_Right_Shift 161
#define Key_Left_Ctrl 162
#define Key_Right_Ctrl 163

namespace Drizzle2D {
	/*
	* Keyboard
	*/
    class Drizzle2D_API Keyboard {
    public:
        bool isKeyPressed(int keyCode, SDL_Window* window);
        bool isKeyReleased(int keyCode, SDL_Window* window);
        bool isKeyHeld(int keyCode, SDL_Window* window);
    };
	/*
	* Mouse
	*/
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
	/*
	* Window
	*/
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
	/*
	* Sprite
	*/
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
	/*
	* Rendering
	*/
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
	/*
	* Audio
	*/
	Drizzle2D_API void InitAudio(int channels);
	class Drizzle2D_API Audio {
	public:
		Audio(const std::string& path, int volume);
		void play();
		void play(int times);
		void set_volume(int volume);

	private:
		std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk*)> chunk;
	};
	/*
	* Threading
	*/
	typedef void (*thread_function_t)(void);
	Drizzle2D_API DWORD WINAPI ThreadFunc(LPVOID lpParam);
	Drizzle2D_API void multithread_function(thread_function_t thread_func);
}