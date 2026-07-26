#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

class Board;
class Game;
#include "board.hpp"


class tile {
public:
    Board* boardptr;
    Game* gameptr;
    Rectangle block;
    bool isMine;
    bool isOpen;
    bool isFlagged;
    int minesArround;
    int adjminesnormal;
    int posx; int posy;


    Color color={167,167,167,255};

    tile(int posx,int posy);

    bool open();
    void flag();
    void assignRect(int cellSize, int spaceBetwen, float scale,int screenx,int screenys);
    void draw(int cellSize, int spaceBetwen, float scale,int screenx,int screenys, Texture2D flag);
};