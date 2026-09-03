#include <iostream>
#include <vector>

#include "menu.hpp"

Menu::Menu(AllMusic* allmusicptr)
: musicButton("textures/menuTextures/music_icon.png", 0.06, false, {4, 5}, allmusicptr), backButton("textures/menuTextures/arrow.png", 0.06, false, {4, 5}), startButton("textures/menuTextures/button_start.png", 0.5, true, {0, -110}), exitButton("textures/menuTextures/button_exit.png", 0.5, true , {0, 110})
{
    background = LoadTexture("textures/menuTextures/background.png");
    back_scale = static_cast<float>(GetScreenHeight()) / background.height;

    choiceBoard = false;

    boardsChoice.reserve(4);
    for(int i = 0; i < 4; i++) boardsChoice.emplace_back("textures/menuTextures/board_button.png", 1.5, true, boardButtonsOffsets[i]);
}

Menu::~Menu()
{
    UnloadTexture(background);
}


void Menu::Input(bool &gameStarted)
{
    if(choiceBoard) for(int i = 0; i < boardsChoice.size(); i++) {
        if(boardsChoice[i].IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {withBoard = i; gameStarted = true;}
        if(backButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) choiceBoard = false;
    } else {
        if(startButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) choiceBoard = true;
        if(exitButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) CloseWindow();

        //changeing music
        if(musicButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_M)) musicButton.ChangeMusic();
    }
}

Board Menu::createBoard()
{
    int with=0, height=0, mines=0;
    if(withBoard == 0) {with = 9; height = 9; mines = 21;}
    if(withBoard == 1) {with = 16; height = 16; mines = 61;}
    if(withBoard == 2) {with = 24; height = 24; mines = 144;}
    if(withBoard == 3) {} //custom
    return {with, height, mines};
}

void Menu::BackgroundDraw()
{
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, back_scale, WHITE);
}

void Menu::Draw()
{
    BackgroundDraw();
    if(choiceBoard) for(int i = 0; i < boardsChoice.size(); i++) {
        //back button draw
        backButton.Draw();
        
        //Board buttons draw
        char* text; int textSize;

        if(i == 0) {text = "EASY"; textSize = 50;}
        else if(i == 1) {text = "MEDIUM"; textSize = 45;}
        else if(i == 2) {text = "HARD"; textSize = 50;}
        else {text = "CUSTOM"; textSize = 40;}
        boardsChoice[i].Draw(); boardsChoice[i].DrawTextInside(text, textSize); 
    } else {
        startButton.Draw();
        exitButton.Draw();
        musicButton.DrawRectangleArownd();
        musicButton.Draw();
    }
}
