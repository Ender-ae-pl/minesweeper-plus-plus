#include <raylib.h>
#include <iostream>
#include <map>

#include "ui.hpp"
#include "board.hpp"

Color backgroundColor = BLACK;
int screenWidth = 1000;
int screenHeight = 1000;

int main() 
{
    InitWindow(screenWidth, screenHeight, "TEMPLATE");
    SetTargetFPS(60);
    
    Board bord(10,10,10); //width, height, mines
    bord.generate(0,0,{});
    bord.print();
    
    while (!WindowShouldClose())
    {
        // Update
        
        
        BeginDrawing();
        ClearBackground(backgroundColor);
            // Draw
            bord.draw(screenWidth, screenHeight);

        EndDrawing();
    }
    
    CloseWindow();
}