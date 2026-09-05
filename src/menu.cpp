#include <iostream>
#include <vector>

#include "menu.hpp"
#include "game.hpp"

void Menu::IsHover(Button_rect *ptr)
{
    if(CheckCollisionPointRec(GetMousePosition(), ptr -> rect)) {
        if(ptr -> IsHovered == false) { ptr -> IsHovered = true; ptr -> ChangeColor(-30);}
    } else { 
        if(ptr -> IsHovered) {ptr -> IsHovered = false; ptr -> ChangeColor(30);}
    }
}

bool Menu::IsCustomButtonsEmpty()
{
    for(const auto& element : customChoice)
    {
        if(element.text.empty()) return true;
    }
    return false;
}

Menu::Menu(AllMusic *allmusicptr, Game* gameptr)
: musicButton("textures/menuTextures/music_icon.png", 0.06, 0, {4, 5}, allmusicptr),
backButton("textures/menuTextures/arrow.png", 0.06, false, {4, 5}),
startButton("textures/menuTextures/button_start.png", 0.5, true, {0, -110}),
exitButton("textures/menuTextures/button_exit.png", 0.5, true, {0, 110}),
confirmButton("confirm", 150, 40, true, {0, 250}, GREEN, 28, BLACK)
{
    background = LoadTexture("textures/menuTextures/background.png");
    back_scale = static_cast<float>(GetScreenHeight()) / background.height;

    place = 0;

    boardsChoice.reserve(4);
    for(int i = 0; i < 4; i++) boardsChoice.emplace_back("textures/menuTextures/board_button.png", 1.5, true, boardButtonsOffsets[i]);

    //Adding customBoardsButtons
    customChoice.push_back(Button_writting{200, 75, true, {0, -250}, WHITE, true, 50, BLACK, "WIDTH:"});
    customChoice.push_back(Button_writting{200, 75, true, {0, -70}, WHITE, true, 50, BLACK, "HEIGHT:"});
    customChoice.push_back(Button_writting{200, 75, true, {0, 110}, WHITE, true, 50, BLACK, "MINES:"});

    IsTyping = 0;
    wchihBoard = 0;

    this -> gameptr = gameptr;
}

Menu::~Menu()
{
    UnloadTexture(background);
}


void Menu::Input(bool &gameStarted)
{
    if(place == 1) for(int i = 0; i < boardsChoice.size(); i++) {
        if(boardsChoice[i].IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {wchihBoard = i; if(i != 3) {gameStarted = true;}}
        if(backButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) place = 0;
    } else if(place == 0) {
        if(startButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) place = 1;
        if(exitButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) CloseWindow();

        //changeing music
        if(musicButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_M)) musicButton.ChangeMusic();
    } else if(place == 2) {
        //Confirm button hover
        IsHover(&confirmButton);

        //Starting game (custom button & enter)
        if((confirmButton.IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (IsTyping == 2 && IsKeyPressed(KEY_ENTER))) && !IsCustomButtonsEmpty()) {
            gameptr -> customWidth = std::stoi(customChoice[0].text);
            gameptr -> customHeight = std::stoi(customChoice[1].text);
            gameptr -> customMines = std::stoi(customChoice[2].text);
            gameStarted = true;
            if(gameptr -> customMines > gameptr -> customWidth * gameptr -> customHeight - 9) {gameStarted = false;}
        }

        //Custom board buttons input & hover
        //Tab
        if((!IsKeyDown(KEY_LEFT_SHIFT) && !IsKeyDown(KEY_RIGHT_SHIFT)) && IsKeyPressed(KEY_TAB)) {if(IsTyping != 2) IsTyping++;}
        else if((IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) && IsKeyPressed(KEY_TAB)) {if(IsTyping != 0) IsTyping--;}

        for (int i = 0; i < customChoice.size(); i++)
        {
            IsHover(&customChoice[i]);

            //Click
            if(customChoice[i].IsPressd(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) IsTyping = i;
            if(IsTyping == i) customChoice[i].Input();
        }
    }
}

Board Menu::createBoard()
{
    int with=0, height=0, mines=0;
    if(wchihBoard == 0) {with = 9; height = 9; mines = 21;}
    if(wchihBoard == 1) {with = 16; height = 16; mines = 61;}
    if(wchihBoard == 2) {with = 24; height = 24; mines = 144;}
    if(wchihBoard == 3) {with = gameptr -> customWidth; height = gameptr -> customHeight; mines = gameptr -> customMines;}
    return {with, height, mines};
}

void Menu::BackgroundDraw()
{
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, back_scale, WHITE);
}

void Menu::Draw()
{
    BackgroundDraw();
    if(place == 1) for(int i = 0; i < boardsChoice.size(); i++) {
        //back button draw
        backButton.Draw();
        
        //Board buttons draw
        char* text; int textSize;

        if(i == 0) {text = "EASY"; textSize = 50;}
        else if(i == 1) {text = "MEDIUM"; textSize = 45;}
        else if(i == 2) {text = "HARD"; textSize = 50;}
        else {text = "CUSTOM"; textSize = 40;}
        boardsChoice[i].Draw(); boardsChoice[i].DrawTextInside(text, textSize); 
    } else if(place == 0) {
        startButton.Draw();
        exitButton.Draw();
        musicButton.DrawRectangleArownd();
        musicButton.Draw();
    } else if(place == 2) {
        for(int i = 0; i < customChoice.size(); i++) {
            customChoice[i].Draw();
            if(IsTyping == i) customChoice[i].DrawLine();
        }
        confirmButton.Draw();
    }
}
