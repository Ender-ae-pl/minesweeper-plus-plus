#include <raylib.h>
#include <iostream>
#include <map>

#include "menu.hpp"
#include "AllMusic.hpp"

Color backgroundColor = GRAY;
const int screenWidth = 1000;
const int screenHeight = 1000;
bool gameStarted = false;

int main()
{
    
    InitWindow(screenWidth, screenHeight, "MINESWEEPER++");
    SetTargetFPS(60);
    
    AllMusic allmusic = AllMusic();
    Game *game;
    Menu menu = Menu(&allmusic);
    
    //Music
    PlayMusicStream(allmusic.backMusic);

    while (!WindowShouldClose())
    {
        //Music update
        UpdateMusicStream(allmusic.backMusic);

        //Input
        if(gameStarted) game->input();
        else {menu.Input(gameStarted); if(gameStarted) {game = new Game(menu.createGame(&allmusic));}}

        // Update
        if(gameStarted) game->updateAll();
        if(allmusic.mustChangeMusic) allmusic.changeMuisc();
        
        BeginDrawing();
        ClearBackground(backgroundColor);
            // Draw
            if(gameStarted) game->drawAll();
            else menu.Draw();

        EndDrawing();
    }

    delete game;
    
    CloseWindow();
}