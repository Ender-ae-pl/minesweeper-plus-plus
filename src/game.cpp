#include <iostream>

#include "game.hpp"
#include "board.hpp"
#include "tile.hpp"
#include "Random.hpp"

Game::Game()
:board(200, 100, 1800) //width, height, mines
{
    board.gameptr=this;
    board.generate(0,0,{});
    cout<<"GAME: "<<this<<endl;
    //ui = Ui();

    Random rng;
    int random = rng.RandInt(1, 3);
    
    InitAudioDevice();

    if(random == 1) backMusic = LoadMusicStream("Sounds/wietnam.mp3");
    else if(random == 2) backMusic = LoadMusicStream("Sounds/tetris.mp3");
    else backMusic = LoadMusicStream("Sounds/zsrr.mp3");
    
    explosion = LoadSound("Sounds/explosion.mp3");
}

Game::~Game()
{
    UnloadMusicStream(backMusic);
    UnloadSound(explosion);
    CloseAudioDevice();
}

void Game::explode_board()
{
    PlaySound(explosion);
    board.isBoardExploded = true;
}

void Game::input()
{
    board.assign();

    Vector2 mouse = GetMousePosition();

    //left click
    if(!board.isBoardExploded) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
            if(CheckCollisionPointRec(mouse, board.board[w][h].block)){
                tile* clickedTile = &board.board[w][h];
                if(clickedTile->isOpen){
                    //CHORDING
                    if(board.ApplyToAdjacent(clickedTile,[](tile* t){int flags=0;flags+=t->isFlagged;return flags;})==clickedTile->minesArround){
                        board.ApplyToAdjacent(clickedTile,[](tile* t){

                        if(t->isFlagged){return 1;}
                        t->open();
                        return 0;

                        });
                    }
                } else {
                    if(clickedTile->isFlagged){continue;}

                    clickedTile->open();
                    
                }
            }
            }
        }

        //right click
        for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
            if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) board.board[w][h].flag();
    
        }
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
    if(board.isBoardExploded) StopMusicStream(backMusic);
}

