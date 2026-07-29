#include <raylib.h>
#include <iostream>
#include <map>

#include "ui.hpp"
#include "board.hpp"
#include "game.hpp"

Color backgroundColor = GRAY;
int screenWidth = 1000;
int screenHeight = 1000;

int main()
{
    
    InitWindow(screenWidth, screenHeight, "MINESWEEPER++");
    SetTargetFPS(60);
    
    Game game = Game();
    game.print();
    
    //Music
    PlayMusicStream(game.backMusic);

    while (!WindowShouldClose())
    {
        //Music update
        UpdateMusicStream(game.backMusic);

        //Input
        game.input();

        // Update
        game.updateAll();
        
        BeginDrawing();
        ClearBackground(backgroundColor);
            // Draw
            game.drawAll();

        EndDrawing();
    }
    
    CloseWindow();
}