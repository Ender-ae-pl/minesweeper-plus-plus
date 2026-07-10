#include <raylib.h>
#include <iostream>
#include <map>

#include "ui.hpp"
#include "board.hpp"
#include "game.hpp"

Color backgroundColor = BLACK;
int screenWidth = 1000;
int screenHeight = 1000;

int main()
{
    InitWindow(screenWidth, screenHeight, "TEMPLATE");
    SetTargetFPS(60);

    Game game = Game();
    game.print();
    
    while (!WindowShouldClose())
    {
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