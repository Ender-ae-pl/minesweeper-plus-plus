#include <iostream>

#include "game.hpp"
#include "board.hpp"

Game::Game()
:board(15, 20, 10) //width, height, mines
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

    for (int w = 0; w < board.width; w++) for (int h = 0; h < board.height; h++){
        if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(board.board[w][h].open()) {
                PlaySound(explosion);
                WaitTime(2);
                CloseWindow();
            } else {
                board.board[w][h].color = WHITE;
                board.board[w][h].isOpen = true;
            }
        }
        if(CheckCollisionPointRec(mouse, board.board[w][h].block) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) board.board[w][h].flag();
    }

    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){
        board.move_up();
    }

    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){
        board.move_down();
    }

    if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)){
        board.move_left();
    }

    if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)){
        board.move_right();
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

