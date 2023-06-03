# Making Sprites
Start by making a Sprite using the Sprite Class
```
Sprite NewSprite;
```
Make sure to assign it a unique class or it will be an invalid class
```
NewSprite.class_name = (char*)"NewSprite1";
```
# Texturizing Sprites
To give the Sprite a Texture use
```
TexturizeSpriteBMP(&NewSprite, &GameWindow, (char*)"Player.bmp");
```
# Adding Sprites
To add the Sprite to the Rendering Array use
```
GameRender.AddSprite(NewSprite);
```
# Sprite Positions
To change the positions or to overlap a sprite use
```
NewSprite.PosX = 0;
NewSprite.PosY = 1;
NewSprite.PosZ = -1; // -1 to go over and 1 to go under
```
# Rotating Sprites
To Rotate Sprites use
```
NewSprite.rotationTurn = 90;
```
# Scaling Sprites
To change the scale/size of the sprite use
```
NewSprite.ScaleW = 0.5; // Make it smaller
NewSprite.ScaleH = 2; // Make it Bigger
```
# Sprite Health
```
NewSprite.HealthMax = 3;
NewSprite.CurrentHealth = 3;
```
# Moving Sprites
```
NewSprite.PosX += 5;
GameRender.ChangeSprite(NewSprite);
NewSprite.PosX += 5;
GameRender.ChangeSprite(NewSprite);
```
# Deleting Sprites
```
GameRender.DeleteSprite(NewSprite.class_name);
```
# Finding Sprites
```
Sprite sd = GameRender.FindSprite((char*)"NewSprite");
```
