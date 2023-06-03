# Keyboard Input
Start By Creating a Keyboard Class
```
Keyboard GameKeyboard;
```

# Getting Key Presses
```
if (GameKeyboard.isKeyPressed(Key_W, GameWindow.window)) {
    // Your Code Goes Here
}
```
# Getting Key Releases
```
if (GameKeyboard.isKeyReleased(Key_W, GameWindow.window)) {
    // Your Code Goes Here
}
```
# Getting Hot Keys
```
if (GameKeyboard.isKeyHeld(Key_W, GameWindow.window) && GameKeyboard.isKeyHeld(Key_A, GameWindow.window)) {
    // Your Code Goes Here
}
```
