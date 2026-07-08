#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

class Board;
#include "board.hpp"

class tile {
public:
    bool state;
    Rectangle block;
    bool isMine;
    int adjminesnormal;
    int posx; int posy;
    Board* boardptr;

    tile(int posx,int posy);

    void open();
    void flag();
    void draw(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
};