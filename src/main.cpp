#include <raylib.h>
#include <iostream>
#include <map>

#include "game.hpp"
#include "menu.hpp"

Color backgroundColor = GRAY;
const int screenWidth = 1000;
const int screenHeight = 1000;
bool gameStarted = false;

int main()
{
    
    InitWindow(screenWidth, screenHeight, "MINESWEEPER++");
    SetTargetFPS(60);
    
    Game game = Game();
    Menu menu = Menu();
    
    //Music
    PlayMusicStream(game.backMusic);

    while (!WindowShouldClose())
    {
        //Music update
        UpdateMusicStream(game.backMusic);

        //Input
        if(gameStarted) game.input();
        else menu.Input(gameStarted);

        // Update
        if(gameStarted) game.updateAll();
        
        BeginDrawing();
        ClearBackground(backgroundColor);
            // Draw
            if(gameStarted) game.drawAll();
            else menu.Draw();

        EndDrawing();
    }
    
    CloseWindow();
}