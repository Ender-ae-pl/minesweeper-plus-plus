#include <raylib.h>
#include <iostream>
#include <map>

#include "ui.hpp"
#include "board.hpp"
#include "game.hpp"
#include "Random.hpp"

Color backgroundColor = BLACK;
int screenWidth = 1000;
int screenHeight = 1000;

int main()
{
    
    InitWindow(screenWidth, screenHeight, "MINESWEEPER++");
    SetTargetFPS(60);
    
    Game game = Game();
    game.print();
    
    //Music
    Random rng;
    int random = rng.RandInt(1, 3);
    if(random == 1) PlayMusicStream(game.backMusic1);
    else if(random == 2) PlayMusicStream(game.backMusic2);
    else PlayMusicStream(game.backMusic3);

    while (!WindowShouldClose())
    {
        //Music update
        if(random == 1) UpdateMusicStream(game.backMusic1);
        else if(random == 2) UpdateMusicStream(game.backMusic2);
        else UpdateMusicStream(game.backMusic3);

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