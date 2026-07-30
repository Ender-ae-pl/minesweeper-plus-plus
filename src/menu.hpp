#pragma once

#include <raylib.h>
#include <vector>

#include "button.hpp"
#include "button_music.hpp"

class Menu
{
    Texture2D background; float back_scale;
    Button_music musicButton;
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