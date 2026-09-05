#include <iostream>

#include "game.hpp"
#include "board.hpp"
#include "tile.hpp"
#include "Random.hpp"

Game::Game(AllMusic* allmusicptr)
:menu(allmusicptr, this)
{
    //ui = Ui();
    explosion = LoadSound("Sounds/explosion.mp3");
    this->allmusicptr = allmusicptr;

    gameStarted = false;
}

Game::~Game()
{
    UnloadSound(explosion);
    delete boardptr;
}

void Game::explode_board()
{
    PlaySound(explosion);
    boardptr -> isBoardExploded = true;
}

void Game::input()
{
    if(gameStarted)
    {
        boardptr -> assign();

        //scroll
        boardptr -> scale = max(boardptr -> minscale,boardptr -> scale+GetMouseWheelMove()*0.1f);
        
        //movement
        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
            boardptr -> screenPos.y-=5/boardptr -> scale;  
        }
        
        if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
            boardptr -> screenPos.y+=5/boardptr -> scale;
        }
        
        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
            boardptr -> screenPos.x-=5/boardptr -> scale;
        }
        
        if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
            boardptr -> screenPos.x+=5/boardptr -> scale;
        }

        //changeing music
        if(IsKeyPressed(KEY_M)) allmusicptr->changeMuisc();

        //corrections when going off-screen;
        int boardWidth = boardptr -> width*boardptr -> cellSize;
        int boardHeight = boardptr -> height*boardptr -> cellSize;
        boardptr -> screenPos.x=max(0.0f,boardptr -> screenPos.x);
        boardptr -> screenPos.y=max(0.0f,boardptr -> screenPos.y);
        boardptr -> screenPos.x-=max(0.0f,boardptr -> screenPos.x+GetScreenWidth()/boardptr -> scale-(float)boardWidth);
        boardptr -> screenPos.y-=max(0.0f,boardptr -> screenPos.y+GetScreenHeight()/boardptr -> scale-(float)boardHeight);
        
        
        ///Turning to menu when player click any key when game is over
        int keyPressed = GetKeyPressed();
        if(keyPressed != 0 && boardptr -> isBoardExploded) {
            PlayMusicStream(allmusicptr->backMusic);
            boardptr -> isBoardExploded = false;
            gameStarted = false;
            menu.place = 0;
            menu.wchihBoard = 0;
        } else if(keyPressed != 0 && boardptr -> winGame) {
            boardptr -> winGame = false;
            gameStarted = false;
            menu.place = 0;
            menu.wchihBoard = 0;
        }


        if(!boardptr -> isBoardExploded && !boardptr -> winGame) {
            Vector2 mouse = GetMousePosition();
            
            //left click
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                for (int w = 0; w < boardptr -> width; w++) for (int h = 0; h < boardptr -> height; h++){
                    if(CheckCollisionPointRec(mouse, boardptr -> board[w][h].block)){
                        tile* clickedTile = &boardptr -> board[w][h];
                        if(clickedTile->isOpen){
                            //CHORDING
                            if(boardptr -> ApplyToAdjacent(clickedTile,[](tile* t){int flags=0;flags+=t->isFlagged;return flags;})==clickedTile->minesArround){
                                boardptr -> ApplyToAdjacent(clickedTile,[](tile* t){
                                    
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
            for (int w = 0; w < boardptr -> width; w++) for (int h = 0; h < boardptr -> height; h++){
                if(CheckCollisionPointRec(mouse, boardptr -> board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) boardptr -> board[w][h].flag();
            }
        }
    } else {
        menu.Input(gameStarted);
        if(gameStarted) {
            boardptr = new Board(menu.createBoard());
            boardptr -> gameptr = this;
            boardptr -> generate(0,0,{});
        } else if(menu.wchihBoard == 3) {
            menu.place = 2;
        }
    }
}

void Game::drawAll()
{
    if(gameStarted) boardptr -> draw();
    else {menu.BackgroundDraw(); menu.Draw();}
    //ui.draw(🙏);
}

void Game::print()
{
    boardptr -> print();    
}

void Game::updateAll()
{
    if(gameStarted) {boardptr -> update(); if(boardptr -> isBoardExploded) StopMusicStream(allmusicptr->backMusic);}
}

