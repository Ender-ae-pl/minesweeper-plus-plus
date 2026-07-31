#pragma once

#include <raylib.h>
#include <vector>

#include "game.hpp"
#include "button.hpp"
#include "button_music.hpp"

class Menu
{
    Texture2D background; float back_scale;
    Button_music musicButton;
    Button startButton;
    Button exitButton;

    std::vector<Button> boardsChoice;
    std::vector<Vector2> boardButtonsOffsets = {{-200, -150}, {200, -150}, {-200, 150}, {200, 150}};

    bool choiceBoard;
    int withBoard;

    public:
    Menu(AllMusic* allmusicptr);
    ~Menu();

    Game createGame(AllMusic* allmusicptr);
    void BackgroundDraw();
    void Input(bool &gameStarted);
    void Draw();
};