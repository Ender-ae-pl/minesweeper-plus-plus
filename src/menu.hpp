#pragma once

#include <raylib.h>
#include <vector>

#include "board.hpp"
#include "button.hpp"
#include "button_music.hpp"
#include "button_writting.hpp"
#include "button_rect.hpp"

class Game;

class Menu
{
    Game* gameptr;
    
    Texture2D background; float back_scale;
    Button_music musicButton;
    Button backButton;
    Button startButton;
    Button exitButton; 
    
    //Board choice buttons
    std::vector<Button> boardsChoice;
    std::vector<Vector2> boardButtonsOffsets = {{-200, -150}, {200, -150}, {-200, 150}, {200, 150}};
    int IsTyping; // 0 - widthCustonButton, 1 - heightCustomButton, 2 - minesCustomButton
    
    //Custom board buttons
    std::vector<Button_writting> customChoice;
    Button_rect confirmButton;
    
    void IsHover(Button_rect* ptr);
    bool IsCustomButtonsEmpty();
    
    public:
    int place; // 0 - menu, 1 - choice a board, 2 - custom board
    int wchihBoard;
    
    Menu(AllMusic* allmusicptr, Game* gameptr);
    ~Menu();

    Board createBoard();
    void BackgroundDraw();
    void Input(bool &gameStarted);
    void Draw();
};