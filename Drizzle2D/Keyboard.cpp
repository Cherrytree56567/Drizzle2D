#include "Keyboard.h"

namespace Drizzle2D {
    bool isWindowFocuseds(SDL_Window* window) {
        Uint32 flags = SDL_GetWindowFlags(window);
        return (flags & SDL_WINDOW_INPUT_FOCUS) != 0;
    }

    bool Keyboard::isKeyPressed(int keyCode, SDL_Window* window) {
        static bool keyStates[256] = { false };
        bool currentKeyState = GetAsyncKeyState(keyCode) & 0x8000;
        bool isPressed = currentKeyState && !keyStates[keyCode];
        keyStates[keyCode] = currentKeyState;
        return isPressed && isWindowFocuseds(window);
    }

    bool Keyboard::isKeyReleased(int keyCode, SDL_Window* window) {
        static bool keyStates[256] = { false };
        bool currentKeyState = GetAsyncKeyState(keyCode) & 0x8000;
        bool isReleased = keyStates[keyCode] && !currentKeyState;
        keyStates[keyCode] = currentKeyState;
        return isReleased && isWindowFocuseds(window);
    }
    bool Keyboard::isKeyHeld(int keyCode, SDL_Window* window) {
        return GetAsyncKeyState(keyCode) & 0x8000 && isWindowFocuseds(window);
    }
}