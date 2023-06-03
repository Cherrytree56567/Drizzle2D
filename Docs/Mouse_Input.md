# Mouse Input
Start By Creating a Mouse Class
```
Mouse GameMouse;
```
# Getting Left clicks
Getting Left Click
```
if (IsMouseLeftPressed(GameWindow.window)){
   // Your Code Goes Here
}
```
Getting Left Click Release
```
if (IsMouseLeftReleased(GameWindow.window)){
   // Your Code Goes Here
}
```
# Getting Right clicks
Getting Right Click
```
if (IsMouseRightPressed(GameWindow.window)){
   // Your Code Goes Here
}
```
Getting Right Click Release
```
if (IsMouseRightReleased(GameWindow.window)){
   // Your Code Goes Here
}
```
# Getting Both Clicks At Once
```
if (IsMouseRightHeld(GameWindow.window) && IsMouseRLeftHeld(GameWindow.window)){
    // Your Code Goes Here
}
```
# Getting Mouse Positions
```
int MouseX = GetMouseX();
int MouseY = GetMouseY();
```
# Getting Scroll Wheel Delta
```
int SWD = GetScrollWheelDelta();
```
