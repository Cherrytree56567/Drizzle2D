#include <iostream>
#include "Window.h"

void Update() {

}

int main() {
    Window GameWindow;

    GameWindow.CreateWindow();

    while (!GameWindow.Mainloop()) {
        Update();
    }

    GameWindow.CloseWindow();

    return 0;
}