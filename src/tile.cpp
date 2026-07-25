#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "tile.hpp"

tile::tile(int posx, int posy){
    this->posx=posx;
    this->posy=posy;
    this->minesArround = 0;
    this->isOpen = false;
    isMine=false;
    isFlagged=false;
}

bool tile::open()
{
    if (isOpen) return false;
    isOpen = true;
    if (isMine){
        return true;
    }
    
    if (minesArround==0){
        boardptr->ApplyToAdjacent(this,[](tile* t){
            t->open();
            return 0;
        });
    }

    return false;
}

void tile::flag()
{
    isFlagged = !isFlagged;
}

void tile::assignRect(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    block = {scale * (spaceBetwen/2 + posx * cellSize)  -screenx,scale *  (spaceBetwen/2 + posy * cellSize)  -screeny, (cellSize - spaceBetwen)*scale, (cellSize - spaceBetwen)*scale};
}

void tile::draw(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    Color colorBorder = GRAY;
    Color colorClosed = {167,167,167,255};

    
    //lines (bigger squares)
    DrawRectangle(scale *  (posx * cellSize)  -screenx,scale *  (posy * cellSize)  -screeny, (cellSize)*scale, (cellSize)*scale,colorBorder);
    
    if(isOpen){
        DrawRectangleRec(block, color);
        float fontSize = 35;
        if(minesArround==0){return;}
        DrawText(TextFormat("%i", minesArround) , block.x + (block.width - MeasureText(TextFormat("%i", minesArround), fontSize))/2, block.y + (block.height - fontSize)/2, fontSize, BLACK);
    } else {
        if(isFlagged) colorClosed = ORANGE;
        DrawRectangleRec(block, colorClosed);
    }
}