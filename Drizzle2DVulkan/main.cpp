#include <iostream>
#include "Window.h"

void Update() {

}

int main() {
    Window GameWindow;

    GameWindow.CreateWin();

    while (!GameWindow.Mainloop()) {
        Update();
    }

    GameWindow.CloseWindow();

    return 0;
}