#include <raylib.h>
#include <iostream>
#include <map>

#include "ui.hpp"
#include "board.hpp"

Color backgroundColor = WHITE;
int screenWidth = 800;
int screenHeight = 600;

int main() 
{
    InitWindow(screenWidth, screenHeight, "TEMPLATE");
    SetTargetFPS(60);
    
    Board bord(10,10,10,30,4); //width, height, mines, cellSize, spaceBetwen
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