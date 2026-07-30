#pragma once

#include <raylib.h>
#include <vector>

#include "button.hpp"

class Menu
{
    Texture2D background; float back_scale;
    Button musicButton;
    Button startButton;
    Button exitButton;
    std::vector<Button> boardsChoice;

    bool choiceBoard;

    public:
    Menu(AllMusic* allmusicptr);
    ~Menu();

    void BackgroundDraw();
    void Input(bool &gameStarted);
    void Draw();
};