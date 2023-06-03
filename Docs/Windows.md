# Creating Windows
First you need to make a copy of the C++ class
```
Window GameWindow;
```
Then you would need to Create the window
```
GameWindow.CreateWin();
```
Finally make a GameLoop
```
while (!GameWindow.mainloop()) {

}
```
# Window Names
To change the Window Name use: \n
```
GameWindow.WinTitle = (char*)"New Game";
```
# Background Color
To change Background Color use: \n
```
GameWindow.bgcolor = { 255, 255, 0, 255 };
```
# Window Positions
To change Window Position use: \n
```
GameWindow.WinX = 100;
GameWindow.WinY = 100;
```
# Window Size
```
GameWindow.WinWidth = 800;
GameWindow.WinHeight = 600;
```
