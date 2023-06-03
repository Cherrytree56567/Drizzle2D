# Getting Started
First Install [SDL2](https://github.com/libsdl-org/SDL/releases) and [SDL2_Mixer](https://github.com/libsdl-org/SDL_mixer/releases) and install it into a c++ IDE (Visual Studio 2022 C++20 Recommended).<br>
Add the Include Directory for SDL2, SDL2 Mixer and Drizzle2D.<br>
Add the Lib Directory for SDL2, SDL2 Mixer and Drizzle2D.<br>
Write a simple Program like: <br>
```
#include <iostream>
#include <Drizzle2D.h>

using namespace Drizzle2D;

int main(int argc, char* argv[]) {
    Window GameWindow;
    Rendering Render;
    GameWindow.CreateWin();
    while (!GameWindow.mainloop()) {
        Render.Render(&GameWindow);
    }
    return 0;
}

```
