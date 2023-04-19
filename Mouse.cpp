#include "Mouse.h"
#include <Windows.h>
#include <Windowsx.h>

namespace Drizzle2D {
    bool isWindowFocused(SDL_Window* window) {
        Uint32 flags = SDL_GetWindowFlags(window);
        return (flags & SDL_WINDOW_INPUT_FOCUS) != 0;
    }

    bool Mouse::IsMouseLeftPressed(SDL_Window* window) {
        return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 && isWindowFocused(window);
    }

    bool Mouse::IsMouseLeftReleased(SDL_Window* window) {
        return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) == 0 && isWindowFocused(window);
    }

    bool Mouse::IsMouseLeftHeld(SDL_Window* window) {
        return (GetKeyState(VK_LBUTTON) & 0x8000) != 0 && isWindowFocused(window);
    }

    bool Mouse::IsMouseRightPressed(SDL_Window* window) {
        return (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0 && isWindowFocused(window);
    }

    bool Mouse::IsMouseRightReleased(SDL_Window* window) {
        return (GetAsyncKeyState(VK_RBUTTON) & 0x8000) == 0 && isWindowFocused(window);
    }

    bool Mouse::IsMouseRightHeld(SDL_Window* window) {
        return (GetKeyState(VK_RBUTTON) & 0x8000) != 0 && isWindowFocused(window);
    }

    int Mouse::GetMouseX() {
        int x, y;
        Uint32 mouse_state = SDL_GetMouseState(&x, &y);
        return x;
    }
    
    int Mouse::GetMouseY() {
        int x, y;
        Uint32 mouse_state = SDL_GetMouseState(&x, &y);
        return y;
    }

    int Mouse::GetScrollWheelDelta() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEWHEEL:
                return event.wheel.y;
                break;
                // Handle other event types as necessary...
            }
        }
    }
}