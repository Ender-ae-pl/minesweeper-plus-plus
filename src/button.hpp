#pragma once
#include <raylib.h>
#include <vector>

#include "AllMusic.hpp"

class Button
{
    AllMusic* allmusicptr;
    Texture2D texture;
    Vector2 posicion;
    bool IsClicked;

    //Specyfic for music button
    Color rectArowndClolor;
    int music;

    public:
    void ChangeMusic();

    Button(const char* imagePath, float scale, bool doCenter, Vector2 offset = {0, 0}, AllMusic* allmusicptr = nullptr, Color rectArowndClolor = RED);
    ~Button();
    
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    Vector2 GetCenterPosicion();
    void DrawRectangleArownd();
    void Draw();
};