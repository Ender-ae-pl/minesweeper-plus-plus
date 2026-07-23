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
    bool isOpen;
    int minesArround;
    int adjminesnormal;
    int posx; int posy;
    Board* boardptr;
    Color color;

    tile(int posx,int posy, int minesArround = 0, Color color=BLUE, bool isOpen = false);

    bool open();
    void flag();
    void assignRect(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
    void draw(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
};