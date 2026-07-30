#include <iostream>
#include "menu.hpp"

Menu::Menu(AllMusic* allmusicptr)
: musicButton("textures/menuTextures/music_icon.png", 0.06, false, {4, 5}, allmusicptr), startButton("textures/menuTextures/button_start.png", 0.5, true, {0, -110}), exitButton("textures/menuTextures/button_exit.png", 0.5, true , {0, 110})
{
    background = LoadTexture("textures/menuTextures/background.png");
    back_scale = static_cast<float>(GetScreenHeight()) / background.height;

    choiceBoard = false;
}

Menu::~Menu()
{
    UnloadTexture(background);
}


void Menu::Input(bool &gameStarted)
{
    if(choiceBoard) for(int i = 0; i < boardsChoice.size(); i++) boardsChoice[i].IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
    else {
        if(startButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) gameStarted = true;
        if(exitButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) CloseWindow();
        if(musicButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) musicButton.ChangeMusic();
    }
}

void Menu::BackgroundDraw()
{
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, back_scale, WHITE);
}

void Menu::Draw()
{
    if(choiceBoard) for(int i = 0; i < boardsChoice.size(); i++) boardsChoice[i].Draw();
    else {
        BackgroundDraw();
        startButton.Draw();
        exitButton.Draw();
        musicButton.DrawRectangleArownd();
        musicButton.Draw();
    }
}
