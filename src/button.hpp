#pragma once
#include <raylib.h>
#include <vector>

#include "AllMusic.hpp"

class Button
{
    protected:
    Texture2D texture;
    Vector2 posicion;
    bool IsClicked;

    public:

    Button(const char* imagePath, float scale, bool doCenter, Vector2 offset = {0, 0});
    ~Button();
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    Vector2 GetCenterPosicion();
    void Draw();
};