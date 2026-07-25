#include <iostream>

#include "game.hpp"
#include "board.hpp"
#include "tile.hpp"

Game::Game()
:board(60, 30, 180) //width, height, mines
{
    board.generate(0,0,{});
    //ui = Ui();

    InitAudioDevice();
    explosion = LoadSound("Sounds/explosion.mp3");
    backMusic1 = LoadMusicStream("Sounds/wietnam.mp3");
    backMusic2 = LoadMusicStream("Sounds/tetris.mp3");
    backMusic3 = LoadMusicStream("Sounds/zsrr.mp3");
}

Game::~Game()
{
    UnloadMusicStream(backMusic1);
    UnloadMusicStream(backMusic2);
    UnloadMusicStream(backMusic3);
    UnloadSound(explosion);
    CloseAudioDevice();
}

void Game::input()
{
    board.assign();

    Vector2 mouse = GetMousePosition();

    //left click
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
            if(CheckCollisionPointRec(mouse, board.board[w][h].block)){
                tile* clickedTile = &board.board[w][h];
                if(clickedTile->isOpen || clickedTile->isFlagged){continue;}

                clickedTile->open();

                if(clickedTile->isMine) {
                    PlaySound(explosion);
                    WaitTime(2);
                    CloseWindow();
                }
            }
        }
    }

    //right click
    for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
        if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) board.board[w][h].flag();
   
    }
    
    //scroll
    board.scale = max(board.minscale,board.scale+GetMouseWheelMove()*0.1f);

    //movement
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        board.screenPos.y-=5/board.scale;  
    }
    
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        board.screenPos.y+=5/board.scale;
    }
    
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        board.screenPos.x-=5/board.scale;
    }
    
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        board.screenPos.x+=5/board.scale;
    }
    //corrections when going off-screen;
    int boardWidth = board.width*board.cellSize;
    int boardHeight = board.height*board.cellSize;
    board.screenPos.x=max(0.0f,board.screenPos.x);
    board.screenPos.y=max(0.0f,board.screenPos.y);
    board.screenPos.x-=max(0.0f,board.screenPos.x+GetScreenWidth()/board.scale-(float)boardWidth);
    board.screenPos.y-=max(0.0f,board.screenPos.y+GetScreenHeight()/board.scale-(float)boardHeight);

}

void Game::drawAll()
{
    board.draw();
    //ui.draw(🙏);
}

void Game::print()
{
    board.print();    
}

void Game::updateAll()
{
    return;
}

