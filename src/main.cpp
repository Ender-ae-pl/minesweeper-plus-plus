#include <raylib.h>
#include <iostream>
#include <map>

#include "game.hpp"
#include "AllMusic.hpp"

Color backgroundColor = GRAY;
const int screenWidth = 1000;
const int screenHeight = 1000;

int main()
{
    
    InitWindow(screenWidth, screenHeight, "MINESWEEPER++");
    SetTargetFPS(60);
    
    AllMusic allmusic = AllMusic();
    Game game(&allmusic);
    
    //Music
    PlayMusicStream(allmusic.backMusic);

    while (!WindowShouldClose())
    {
        //Music update
        UpdateMusicStream(allmusic.backMusic);

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