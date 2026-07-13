#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "tile.hpp"

tile::tile(int posx, int posy, int minesArround , Color color, bool isOpen){
    this->posx=posx;
    this->posy=posy;
    this->color = BLUE;
    this->minesArround = 0;
    this->isOpen = false;
    isMine=false;
}

bool tile::open()
{
    if(isMine) return true;
    else return false;
}

void tile::flag()
{
    return;
}

void tile::assignRect(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    block = {scale * (spaceBetwen/2 + posx * cellSize)  -screenx,scale *  (spaceBetwen/2 + posy * cellSize)  -screeny, (cellSize - spaceBetwen)*scale, (cellSize - spaceBetwen)*scale};
}

void tile::draw(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    Color color2 = GRAY;

    DrawRectangleRec({scale *  (posx * cellSize)  -screenx,scale *  (posy * cellSize)  -screeny, (cellSize)*scale, (cellSize)*scale},color2);
    DrawRectangleRec(block, color);
    if(isOpen){
        float fontSize = 35;
        DrawText(TextFormat("%i", minesArround) , block.x + (block.width - MeasureText(TextFormat("%i", minesArround), fontSize))/2, block.y + (block.height - fontSize)/2, fontSize, BLACK);
    }
}