#include <iostream>
#include "Drizzle2D.h"

using namespace Drizzle2D;

int main(int argc, char* argv[]) {
    Window GameWindow;
    Rendering Render;
    Sprite TestSprite;
    Sprite TestSpsrite;
    TestSpsrite.ScaleW = 0.5;
    TestSpsrite.ScaleH = 0.55;
    TestSpsrite.PosZ = -1;
    TestSpsrite.PosX = 50;
    TestSpsrite.class_name = (char*)"SpriteClss";
    TestSprite.class_name = (char*)"SpriteCls";
    GameWindow.CreateWin();
    TexturizeSpriteBMP(&TestSprite, &GameWindow, (char*)"C:/rd2/Drizzle2D/Drizzle2D/oskar.jpg");
    TexturizeSpriteBMP(&TestSpsrite, &GameWindow, (char*)"C:/rd2/Drizzle2D/Drizzle2D/sdl2.bmp");
    Render.AddSprite(TestSprite);
    Render.AddSprite(TestSpsrite);
    while (!GameWindow.mainloop()) {
        Keyboard GameKeyboard;
        if (GameKeyboard.isKeyPressed(Key_W, GameWindow.window)) {
            TestSpsrite.PosX += 50;
            Render.ChangeSprite(TestSpsrite);
        }
        Render.Render(&GameWindow);
    }
    return 0;
}
