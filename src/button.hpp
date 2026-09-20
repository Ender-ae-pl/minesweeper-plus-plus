#pragma once
#include <raylib.h>
#include <vector>

#include "AllMusic.hpp"

class Button
{
    protected:
    bool IsClicked;
    
    public:
    Texture2D texture;
    Vector2 posicion;

    Button(const char* imagePath, float scale, bool doCenter, Vector2 offset = {0, 0});
    ~Button();
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    void DrawTextInside(const char* text, int textSize);
    Vector2 GetCenterPosicion();
    void Draw();
};