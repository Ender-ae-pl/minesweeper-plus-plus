#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

class Board;
#include "board.hpp"

class tile {
public:
    Rectangle block;
    bool isMine;
    bool isOpen;
    bool isFlagged;
    int minesArround;
    int adjminesnormal;
    int posx; int posy;
    Board* boardptr;

    Color color=LIGHTGRAY;

    tile(int posx,int posy);

    bool open();
    void flag();
    void assignRect(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
    void draw(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
};