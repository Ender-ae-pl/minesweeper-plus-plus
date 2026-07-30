#include "button.hpp"

#include <iostream>
#include <raymath.h>

Button::Button(const char *imagePath, float scale, bool doCenter, Vector2 offset)
{
    Image image = LoadImage(imagePath);
    
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);
    
    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    
    if(doCenter) posicion = Vector2Add(GetCenterPosicion(), offset);
    else posicion = offset;
    
    IsClicked = false;
}

Button::~Button()
{
    UnloadTexture(texture);
}

bool Button::IsPressd(Vector2 mousePosicion, bool mousePressed)
{
    Rectangle rect = {posicion.x, posicion.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};

    if(CheckCollisionPointRec(mousePosicion, rect) && mousePressed) return true;
    return false;
}

Vector2 Button::GetCenterPosicion()
{
    float withCenter = (GetScreenWidth() - texture.width)/2;
    float heightCenter = (GetScreenHeight() - texture.height)/2;

    return {withCenter, heightCenter};
}

void Button::Draw()
{
    DrawTextureV(texture, posicion, WHITE);
}
