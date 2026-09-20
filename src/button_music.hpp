#pragma once

#include "raylib.h"
#include "button.hpp"

class Button_music :public Button
{
    AllMusic* allmusicptr;
    Color rectArowndClolor;
    int music;

    public:
    Button_music(const char* imagePath, float scale, bool doCenter, Vector2 offset = {0, 0}, AllMusic* allmusicptr = nullptr, Color rectArowndClolor = RED);
    ~Button_music();

    void ChangeMusic();
    void DrawRectangleArownd();
};
