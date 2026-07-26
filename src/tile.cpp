#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "tile.hpp"
#include "game.hpp"

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
    isFlagged = false;
    if (isMine){
        cout<<"TILE: "<<gameptr<<endl;
        gameptr->explode();
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
    if(isOpen){return;}
    isFlagged = !isFlagged;
}

void tile::assignRect(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    block = {scale * (spaceBetwen/2 + posx * cellSize  -screenx),scale *  (spaceBetwen/2 + posy * cellSize  -screeny), (cellSize - spaceBetwen)*scale, (cellSize - spaceBetwen)*scale};
}

void tile::draw(int cellSize, int spaceBetwen, float scale, int screenx, int screeny)
{
    Color colorBorder = GRAY;
    Color colorClosed = LIGHTGRAY;

    
    //lines (bigger squares)
    DrawRectangle(scale *  (posx * cellSize-screenx),scale *  (posy * cellSize  -screeny), (cellSize)*scale, (cellSize)*scale,colorBorder);
    
    if(isOpen){
        DrawRectangleRec(block, color);
        if(minesArround==0){return;}
        
        float textHeight = block.height/1.5;
        Vector2 size = MeasureTextEx(GetFontDefault(), TextFormat("%i", minesArround), 100, 0);
        float scale = textHeight / size.y;
        float scaledSize = 100 * scale;
        
        DrawText(TextFormat("%i", minesArround) , block.x + (block.width - MeasureText(TextFormat("%i", minesArround), scaledSize))/2, block.y + (block.height - scaledSize)/2, scaledSize, BLACK);
    } else {
        if(isFlagged) colorClosed = ORANGE;
        DrawRectangleRec(block, colorClosed);
    }
}