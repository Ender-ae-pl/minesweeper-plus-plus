#include <iostream>

#include "game.hpp"
#include "board.hpp"

Game::Game()
:board(15, 20, 1) //width, height, mines
{
    board.generate(0,0,{});
    //ui = Ui();
}

void Game::input()
{
    board.assign();

    Vector2 mouse = GetMousePosition();

    for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
        if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) board.board[w][h].open();
        if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) board.board[w][h].flag();
    }

    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){
        
    }

    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){
        
    }

    if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)){
        
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)){
        
    }
}

void Game::drawAll()
{
    board.draw();
    //ui.draw();
}

void Game::print()
{
    board.print();    
}

void Game::updateAll()
{
    return;
}

